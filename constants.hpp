// constants.hpp
#pragma once
#include <SFML/Graphics/Color.hpp>

namespace Constants {
    // Universal constants
    constexpr double G = 6.67430e-11;   // Gravitational constant
    constexpr double SCALE_DISTANCE = 1.0e-6; // To shrink km → pixels
    constexpr double SCALE_RADIUS   = 2.0e-3; // To shrink real radius → pixels
    constexpr double TIME_STEP      = 60.0 * 60.0; // 1 hour per frame (seconds)

    // Sun
    constexpr double SunMass   = 1.9885e30;
    constexpr double SunRadius = 695700.0; // km
    const sf::Color SunColor   = sf::Color(255, 204, 0); // yellowish

    // Mercury
    constexpr double MercuryMass   = 3.3011e23;
    constexpr double MercuryRadius = 2439.7;   // km
    constexpr double MercuryOrbit  = 57.9e6;   // km
    constexpr double MercuryPeriod = 88.0;     // days
    const sf::Color MercuryColor   = sf::Color(169, 169, 169); // gray

    // Venus
    constexpr double VenusMass   = 4.8675e24;
    constexpr double VenusRadius = 6051.8;
    constexpr double VenusOrbit  = 108.2e6;
    constexpr double VenusPeriod = 224.7;
    const sf::Color VenusColor   = sf::Color(218, 165, 32); // golden

    // Earth
    constexpr double EarthMass   = 5.972e24;
    constexpr double EarthRadius = 6371.0;
    constexpr double EarthOrbit  = 149.6e6;
    constexpr double EarthPeriod = 365.25;
    const sf::Color EarthColor   = sf::Color::Blue;

    // Moon (orbit around Earth, optional)
    constexpr double MoonMass   = 7.3477e22;
    constexpr double MoonRadius = 1737.1;
    constexpr double MoonOrbit  = 384400.0; // km
    constexpr double MoonPeriod = 27.3;     // days
    const sf::Color MoonColor   = sf::Color(200, 200, 200); // light gray

    // Mars
    constexpr double MarsMass   = 6.4171e23;
    constexpr double MarsRadius = 3389.5;
    constexpr double MarsOrbit  = 227.9e6;
    constexpr double MarsPeriod = 687.0;
    const sf::Color MarsColor   = sf::Color(255, 69, 0); // reddish

    // Jupiter
    constexpr double JupiterMass   = 1.8982e27;
    constexpr double JupiterRadius = 69911.0;
    constexpr double JupiterOrbit  = 778.5e6;
    constexpr double JupiterPeriod = 4331.0;
    const sf::Color JupiterColor   = sf::Color(210, 180, 140); // brownish

    // Saturn
    constexpr double SaturnMass   = 5.6834e26;
    constexpr double SaturnRadius = 58232.0;
    constexpr double SaturnOrbit  = 1.434e9;
    constexpr double SaturnPeriod = 10747.0;
    const sf::Color SaturnColor   = sf::Color(222, 184, 135); // sandy

    // Uranus
    constexpr double UranusMass   = 8.6810e25;
    constexpr double UranusRadius = 25362.0;
    constexpr double UranusOrbit  = 2.871e9;
    constexpr double UranusPeriod = 30589.0;
    const sf::Color UranusColor   = sf::Color(173, 216, 230); // cyan

    // Neptune
    constexpr double NeptuneMass   = 1.02413e26;
    constexpr double NeptuneRadius = 24622.0;
    constexpr double NeptuneOrbit  = 4.495e9;
    constexpr double NeptunePeriod = 59800.0;
    const sf::Color NeptuneColor   = sf::Color(72, 61, 139); // dark blue
}
