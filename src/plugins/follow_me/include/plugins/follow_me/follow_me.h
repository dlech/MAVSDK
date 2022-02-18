// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/follow_me/follow_me.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "plugin_base.h"

namespace mavsdk {

class System;
class FollowMeImpl;

/**
 * @brief Allow users to command the vehicle to follow a specific target.
 * The target is provided as a GPS coordinate and altitude.
 */
class FollowMe : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto follow_me = FollowMe(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit FollowMe(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto follow_me = FollowMe(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit FollowMe(std::shared_ptr<System> system); // new

    /**
     * @brief Constructor. Creates the plugin for multiple Systems.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto follow_me = FollowMe(systems);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit FollowMe(std::vector<std::shared_ptr<System>> systems);

    /**
     * @brief Destructor (internal use only).
     */
    ~FollowMe();

    /**
     * @brief Configuration type.
     */
    struct Config {
        /**
         * @brief Direction relative to the target that the vehicle should follow
         */
        enum class FollowDirection {
            None, /**< @brief Do not follow. */
            Behind, /**< @brief Follow from behind. */
            Front, /**< @brief Follow from front. */
            FrontRight, /**< @brief Follow from front right. */
            FrontLeft, /**< @brief Follow from front left. */
        };

        /**
         * @brief Stream operator to print information about a `FollowMe::FollowDirection`.
         *
         * @return A reference to the stream.
         */
        friend std::ostream&
        operator<<(std::ostream& str, FollowMe::Config::FollowDirection const& follow_direction);

        float min_height_m{8.0}; /**< @brief Minimum height for the vehicle in meters (recommended
                                    minimum 8 meters) */
        float follow_distance_m{8.0}; /**< @brief Distance from target for vehicle to follow in
                                         meters (recommended minimum 1 meter) */
        FollowDirection follow_direction{}; /**< @brief Direction to follow in */
        float responsiveness{0.5}; /**< @brief How responsive the vehicle is to the motion of the
                                      target (range 0.0 to 1.0) */
    };

    /**
     * @brief Equal operator to compare two `FollowMe::Config` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const FollowMe::Config& lhs, const FollowMe::Config& rhs);

    /**
     * @brief Stream operator to print information about a `FollowMe::Config`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, FollowMe::Config const& config);

    /**
     * @brief Target location for the vehicle to follow
     */
    struct TargetLocation {
        double latitude_deg{double(NAN)}; /**< @brief Target latitude in degrees */
        double longitude_deg{double(NAN)}; /**< @brief Target longitude in degrees */
        float absolute_altitude_m{float(NAN)}; /**< @brief Target altitude in meters above MSL */
        float velocity_x_m_s{
            float(NAN)}; /**< @brief Target velocity in X axis, in meters per second */
        float velocity_y_m_s{
            float(NAN)}; /**< @brief Target velocity in Y axis, in meters per second */
        float velocity_z_m_s{
            float(NAN)}; /**< @brief Target velocity in Z axis, in meters per second */
    };

    /**
     * @brief Equal operator to compare two `FollowMe::TargetLocation` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const FollowMe::TargetLocation& lhs, const FollowMe::TargetLocation& rhs);

    /**
     * @brief Stream operator to print information about a `FollowMe::TargetLocation`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, FollowMe::TargetLocation const& target_location);

    /**
     * @brief Possible results returned for followme operations
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        NoSystem, /**< @brief No system connected. */
        ConnectionError, /**< @brief Connection error. */
        Busy, /**< @brief Vehicle is busy. */
        CommandDenied, /**< @brief Command denied. */
        Timeout, /**< @brief Request timed out. */
        NotActive, /**< @brief FollowMe is not active. */
        SetConfigFailed, /**< @brief Failed to set FollowMe configuration. */
    };

    /**
     * @brief Stream operator to print information about a `FollowMe::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, FollowMe::Result const& result);

    /**
     * @brief Callback type for asynchronous FollowMe calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Get current configuration.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    FollowMe::Config get_config() const;

    /**
     * @brief Apply configuration by sending it to the system.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_config(Config config) const;

    /**
     * @brief Check if FollowMe is active.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    bool is_active() const;

    /**
     * @brief Set location of the moving target.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_target_location(TargetLocation location) const;

    /**
     * @brief Get the last location of the target.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    FollowMe::TargetLocation get_last_location() const;

    /**
     * @brief Start FollowMe mode.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result start() const;

    /**
     * @brief Stop FollowMe mode.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result stop() const;

    /**
     * @brief Copy constructor.
     */
    FollowMe(const FollowMe& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const FollowMe& operator=(const FollowMe&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<FollowMeImpl> _impl;
};

} // namespace mavsdk