// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/tune/tune.proto)

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
class TuneImpl;

/**
 * @brief Enable creating and sending a tune to be played on the system.
 */
class Tune : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto tune = Tune(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Tune(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto tune = Tune(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Tune(std::shared_ptr<System> system); // new

    /**
     * @brief Destructor (internal use only).
     */
    ~Tune();

    /**
     * @brief An element of the tune
     */
    enum class SongElement {
        StyleLegato, /**< @brief After this element, start playing legato. */
        StyleNormal, /**< @brief After this element, start playing normal. */
        StyleStaccato, /**< @brief After this element, start playing staccato. */
        Duration1, /**< @brief After this element, set the note duration to 1. */
        Duration2, /**< @brief After this element, set the note duration to 2. */
        Duration4, /**< @brief After this element, set the note duration to 4. */
        Duration8, /**< @brief After this element, set the note duration to 8. */
        Duration16, /**< @brief After this element, set the note duration to 16. */
        Duration32, /**< @brief After this element, set the note duration to 32. */
        NoteA, /**< @brief Play note A. */
        NoteB, /**< @brief Play note B. */
        NoteC, /**< @brief Play note C. */
        NoteD, /**< @brief Play note D. */
        NoteE, /**< @brief Play note E. */
        NoteF, /**< @brief Play note F. */
        NoteG, /**< @brief Play note G. */
        NotePause, /**< @brief Play a rest. */
        Sharp, /**< @brief After this element, sharp the note (half a step up). */
        Flat, /**< @brief After this element, flat the note (half a step down). */
        OctaveUp, /**< @brief After this element, shift the note 1 octave up. */
        OctaveDown, /**< @brief After this element, shift the note 1 octave down. */
    };

    /**
     * @brief Stream operator to print information about a `Tune::SongElement`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Tune::SongElement const& song_element);

    /**
     * @brief Tune description, containing song elements and tempo.
     */
    struct TuneDescription {
        std::vector<SongElement> song_elements{}; /**< @brief The list of song elements (notes,
                                                     pauses, ...) to be played */
        int32_t tempo{}; /**< @brief The tempo of the song (range: 32 - 255) */
    };

    /**
     * @brief Equal operator to compare two `Tune::TuneDescription` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const Tune::TuneDescription& lhs, const Tune::TuneDescription& rhs);

    /**
     * @brief Stream operator to print information about a `Tune::TuneDescription`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, Tune::TuneDescription const& tune_description);

    /**
     * @brief Possible results returned for tune requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        InvalidTempo, /**< @brief Invalid tempo (range: 32 - 255). */
        TuneTooLong, /**< @brief Invalid tune: encoded string must be at most 247 chars. */
        Error, /**< @brief Failed to send the request. */
        NoSystem, /**< @brief No system connected. */
    };

    /**
     * @brief Stream operator to print information about a `Tune::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Tune::Result const& result);

    /**
     * @brief Callback type for asynchronous Tune calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Send a tune to be played by the system.
     *
     * This function is non-blocking. See 'play_tune' for the blocking counterpart.
     */
    void play_tune_async(TuneDescription tune_description, const ResultCallback callback);

    /**
     * @brief Send a tune to be played by the system.
     *
     * This function is blocking. See 'play_tune_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result play_tune(TuneDescription tune_description) const;

    /**
     * @brief Copy constructor.
     */
    Tune(const Tune& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Tune& operator=(const Tune&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<TuneImpl> _impl;
};

} // namespace mavsdk