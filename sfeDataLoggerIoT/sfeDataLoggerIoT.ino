/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2024, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

/*
 * Flux Framework based logger.
 *
 */

// Flux framework
#include "sfeDLBoard.h"
#include "sfeDataLogger.h"

#include "sfeDLLed.h"
#include <esp_task_wdt.h>

static const uint32_t kLoopWatchdogTimeoutMS = 5UL * 60UL * 1000UL;


// Our data logger application
sfeDataLogger theDataLogger;

//---------------------------------------------------------------------
// Arduino Setup
//
void setup()
{

    pinMode(kDLBoardEn3v3_SW, OUTPUT); // Enable Qwiic power and I2C
    digitalWrite(kDLBoardEn3v3_SW, HIGH);

    // Start up the framework
    flux.start();

    // GURT-1: reboot if the main loop ever stops running. The timeout is long on purpose: the
    // serial menu and an SD firmware update both hold the loop legitimately. Logging also stops
    // while the menu is open, so rebooting after five minutes in it is the right outcome in flight.
    esp_task_wdt_config_t wdtConfig = {
        .timeout_ms = kLoopWatchdogTimeoutMS,
        .idle_core_mask = 0,
        .trigger_panic = true,
    };
    if (esp_task_wdt_reconfigure(&wdtConfig) != ESP_OK)
        esp_task_wdt_init(&wdtConfig);
    esp_task_wdt_add(NULL);
}

//---------------------------------------------------------------------
// Arduino loop -
void loop()
{

    ///////////////////////////////////////////////////////////////////
    // Flux
    //
    // Just call the Flux framework loop() method. Flux will manage
    // the dispatch of processing to the components that were added
    // to the system during setup.
    if (flux.loop()) // will return true if an action did something
        sfeLED.flash(sfeLED.Blue);

    esp_task_wdt_reset();

    delay(1);
}
