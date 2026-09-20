/*
 *---------------------------------------------------------------------------------
 *
 * Copyright (c) 2022-2024, SparkFun Electronics Inc.
 *
 * SPDX-License-Identifier: MIT
 *
 *---------------------------------------------------------------------------------
 */

#pragma once

// Board ID/Mode information data

// Major version number
#define kDLVersionNumberMajor 1

// Minor version number
#define kDLVersionNumberMinor 5

// Point version number
#define kDLVersionNumberPoint 0

// GURT-1 firmware number. Bump it for EVERY build that gets flashed and record the build in
// gurt1-hab/VERSIONS.md. It is printed in the startup banner and logged as "GURT1 FW" in the
// System Info record, so it is in the SD log and reaches the ground over the LoRa downlink.
#define kGURT1FirmwareVersion 5

// Version string description
#define kDLVersionDescriptor "Version 1.5.0 + GURT-1 fw 5"

// app name/class ID string
#define kDLAppClassNameID "SFE-DATALOGGER-IOT"

// Build number - should come from the build system. If not, set default

#ifndef BUILD_NUMBER
#define BUILD_NUMBER 0
#endif

#define kDLVersionBoardDesc "(c) 2023-2026 SparkFun Electronics"