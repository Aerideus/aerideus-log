/*
	Author: @rasmushugosson
	Last modified: 2023-03-20

	Aerideus Log is a lightweight and easy to use library for console and file
	logging. For information about usage and features, please see documentation 
	(README.md) at https://github.com/Aerideus/AerideusLog. 

	Please read the following license information before use:

	====================================================================================
	
	MIT License

	Copyright (c) 2023 Aerideus
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.

	====================================================================================
 
	Copyright (c) 2023 Aerideus
*/

#include <stdio.h>

// Severity level -----------------------------------------------------------------------------------------------

/// <summary>
/// Used to specifies severity level of Aerides log messages.
/// </summary>
typedef enum {
	TRACE = 0, INFO, WARNING, ERROR, FATAL
} log_level;

/// <summary>
/// Sets the minimum severity required for a console messages to be logged.
/// </summary>
/// <param name="min">is the minimum log_level that will be logged</param>
void ae_log_console_level_set(log_level min);

/// <summary>
/// Sets the minimum severity required for a console messages to be logged.
/// </summary>
/// <param name="min">is the minimum log_level that will be logged</param>
#define AE_LOG_CONSOLE_LEVEL_SET(min) ae_log_console_level_set(min)

/// <summary>
/// Sets the minimum severity required for a file messages to be logged.
/// </summary>
/// <param name="min">is the minimum log_level that will be logged</param>
void ae_log_file_level_set(log_level min);

/// <summary>
/// Sets the minimum severity required for a file messages to be logged.
/// </summary>
/// <param name="min">is the minimum log_level that will be logged</param>
#define AE_LOG_FILE_LEVEL_SET(min) ae_log_file_level_set(min)

// Console ------------------------------------------------------------------------------------------------------

/// <summary>
/// Internal function that should only be called through macros. (AE_LOG_CONSOLE_...)
/// </summary>
/// <param name="l">should not be specified</param>
/// <param name="fn">should not be specified</param>
/// <param name="ln">should not be specified</param>
/// <param name="f">should not be specified</param>
void i_ae_log_console(log_level l, const char* fn, int ln, const char* f, ...);

/// <summary>
/// Internal macro that should not be used
/// </summary>
#define I_AE_LOCATION __FILE__, __LINE__

/// <summary>
/// Logs a message to the console regardless of build type.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE(l, f, ...) i_ae_log_console(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the console regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_TRACE(f, ...) i_ae_log_console(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the console regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_INFO(f, ...) i_ae_log_console(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the console regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_WARNING(f, ...) i_ae_log_console(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the console regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_ERROR(f, ...) i_ae_log_console(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the console regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_FATAL(f, ...) i_ae_log_console(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

#ifdef AE_DEBUG

/// <summary>
/// Logs a message to the console when the build type is Debug.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG(l, f, ...) i_ae_log_console(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the console when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_TRACE(f, ...) i_ae_log_console(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the console when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_INFO(f, ...) i_ae_log_console(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the console when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_WARNING(f, ...) i_ae_log_console(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the console when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_ERROR(f, ...) i_ae_log_console(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the console when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_FATAL(f, ...) i_ae_log_console(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a message to the console when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE(l, f, ...)

/// <summary>
/// Logs a trace message to the console when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_TRACE(f, ...)

/// <summary>
/// Logs an information message to the console when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_INFO(f, ...)

/// <summary>
/// Logs a warning to the console when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_WARNING(f, ...)

/// <summary>
/// Logs an error to the console when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the console when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_FATAL(f, ...)

/// <summary>
/// Logs a message to the console when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST(l, f, ...)

/// <summary>
/// Logs a trace message to the console when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_TRACE(f, ...)

/// <summary>
/// Logs an information message to the console when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_INFO(f, ...)

/// <summary>
/// Logs a warning to the console when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_WARNING(f, ...)

/// <summary>
/// Logs an error to the console when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the console when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_FATAL(f, ...)

#endif // AE_DEBUG

#ifdef AE_RELEASE

/// <summary>
/// Logs a message to the console when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG(l, f, ...)

/// <summary>
/// Logs a trace message to the console when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_TRACE(f, ...)

/// <summary>
/// Logs an information message to the console when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_INFO(f, ...)

/// <summary>
/// Logs a warning to the console when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_WARNING(f, ...)

/// <summary>
/// Logs an error to the console when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the console when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_FATAL(f, ...)

/// <summary>
/// Logs a message to the console when the build type is Release.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE(l, f, ...) i_ae_log_console(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the console when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_TRACE(f, ...) i_ae_log_console(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the console when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_INFO(f, ...) i_ae_log_console(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the console when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_WARNING(f, ...) i_ae_log_console(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the console when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_ERROR(f, ...) i_ae_log_console(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the console when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_FATAL(f, ...) i_ae_log_console(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a message to the console when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST(l, f, ...)

/// <summary>
/// Logs a trace message to the console when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_TRACE(f, ...)

/// <summary>
/// Logs an information message to the console when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_INFO(f, ...)

/// <summary>
/// Logs a warning to the console when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_WARNING(f, ...)

/// <summary>
/// Logs an error to the console when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the console when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_FATAL(f, ...)

#endif // AE_RELEASE

#ifdef AE_DIST

/// <summary>
/// Logs a message to the console when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG(l, f, ...)

/// <summary>
/// Logs a trace message to the console when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_TRACE(f, ...)

/// <summary>
/// Logs an information message to the console when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_INFO(f, ...)

/// <summary>
/// Logs a warning to the console when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_WARNING(f, ...)

/// <summary>
/// Logs an error to the console when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the console when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DEBUG_FATAL(f, ...)

/// <summary>
/// Logs a message to the console when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE(l, f, ...)

/// <summary>
/// Logs a trace message to the console when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_TRACE(f, ...)

/// <summary>
/// Logs an information message to the console when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_INFO(f, ...)

/// <summary>
/// Logs a warning to the console when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_WARNING(f, ...)

/// <summary>
/// Logs an error to the console when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the console when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_RELEASE_FATAL(f, ...)

/// <summary>
/// Logs a message to the console when the build type is Dist.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST(l, f, ...) i_ae_log_console(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the console when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_TRACE(f, ...) i_ae_log_console(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the console when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_INFO(f, ...) i_ae_log_console(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the console when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_WARNING(f, ...) i_ae_log_console(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the console when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_ERROR(f, ...) i_ae_log_console(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the console when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_CONSOLE_DIST_FATAL(f, ...) i_ae_log_console(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

#endif // AE_DIST

/// <summary>
/// Logs a blank line to the console regardless of build type.
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE() printf("\n")

#ifdef AE_DEBUG

/// <summary>
/// Logs a blank line to the console when the build type is Debug.
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_DEBUG() printf("\n")
/// <summary>
/// Logs a blank line to the console when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_RELEASE()
/// <summary>
/// Logs a blank line to the console when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_DIST()

#endif // AE_DEBUG

#ifdef AE_RELEASE

/// <summary>
/// Logs a blank line to the console when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_DEBUG() 
/// <summary>
/// Logs a blank line to the console when the build type is Release.
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_RELEASE() printf("\n")
/// <summary>
/// Logs a blank line to the console when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_DIST()

#endif // AE_RELEASE

#ifdef AE_DIST

/// <summary>
/// Logs a blank line to the console when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_DEBUG()
/// <summary>
/// Logs a blank line to the console when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_RELEASE()
/// <summary>
/// Logs a blank line to the console when the build type is Dist.
/// </summary>
#define AE_LOG_CONSOLE_NEXT_LINE_DIST() printf("\n")

#endif // AE_DIST


// File ---------------------------------------------------------------------------------------------------------

/// <summary>
/// Internal function that should only be called through macros. (AE_LOG_CONSOLE_...)
/// </summary>
/// <param name="l">should not be specified</param>
/// <param name="fn">should not be specified</param>
/// <param name="ln">should not be specified</param>
/// <param name="f">should not be specified</param>
void i_ae_log_file(log_level l, const char* fn, int ln, const char* f, ...);

/// <summary>
/// Exports the log file to a specified path and frees allocated memory.
/// </summary>
/// <param name="p">is the desired path and must end with '.txt'</param>
void ae_log_file_export(const char* p);

/// <summary>
/// Exports the log file to a specified path and frees allocated memory.
/// </summary>
/// <param name="p">is the desired path and must end with '.txt'</param>
#define AE_LOG_FILE_EXPORT(p) ae_log_file_export(p)

/// <summary>
/// Logs a message to the log file regardless of build type.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE(l, f, ...) i_ae_log_file(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the log file regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_TRACE(f, ...) i_ae_log_file(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the log file regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_INFO(f, ...) i_ae_log_file(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the log file regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_WARNING(f, ...) i_ae_log_file(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the log file regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_ERROR(f, ...) i_ae_log_file(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the log file regardless of build type.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_FATAL(f, ...) i_ae_log_file(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

#ifdef AE_DEBUG

/// <summary>
/// Logs a message to the log file when the build type is Debug.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG(l, f, ...) i_ae_log_file(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the log file when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_TRACE(f, ...) i_ae_log_file(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the log file when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_INFO(f, ...) i_ae_log_file(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the log file when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_WARNING(f, ...) i_ae_log_file(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the log file when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_ERROR(f, ...) i_ae_log_file(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the log file when the build type is Debug.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_FATAL(f, ...) i_ae_log_file(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a message to the log file when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE(l, f, ...)

/// <summary>
/// Logs a trace message to the log file when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_TRACE(f, ...)

/// <summary>
/// Logs an information message to the log file when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_INFO(f, ...)

/// <summary>
/// Logs a warning to the log file when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_WARNING(f, ...)

/// <summary>
/// Logs an error to the log file when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the log file when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_FATAL(f, ...)

/// <summary>
/// Logs a message to the log file when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST(l, f, ...)

/// <summary>
/// Logs a trace message to the log file when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_TRACE(f, ...)

/// <summary>
/// Logs an information message to the log file when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_INFO(f, ...)

/// <summary>
/// Logs a warning to the log file when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_WARNING(f, ...)

/// <summary>
/// Logs an error to the log file when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the log file when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_FATAL(f, ...)

#endif // AE_DEBUG

#ifdef AE_RELEASE

/// <summary>
/// Logs a message to the log file when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG(l, f, ...)

/// <summary>
/// Logs a trace message to the log file when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_TRACE(f, ...)

/// <summary>
/// Logs an information message to the log file when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_INFO(f, ...)

/// <summary>
/// Logs a warning to the log file when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_WARNING(f, ...)

/// <summary>
/// Logs an error to the log file when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the log file when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_FATAL(f, ...)

/// <summary>
/// Logs a message to the log file when the build type is Release.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE(l, f, ...) i_ae_log_file(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the log file when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_TRACE(f, ...) i_ae_log_file(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the log file when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_INFO(f, ...) i_ae_log_file(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the log file when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_WARNING(f, ...) i_ae_log_file(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the log file when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_ERROR(f, ...) i_ae_log_file(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the log file when the build type is Release.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_FATAL(f, ...) i_ae_log_file(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a message to the log file when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST(l, f, ...)

/// <summary>
/// Logs a trace message to the log file when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_TRACE(f, ...)

/// <summary>
/// Logs an information message to the log file when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_INFO(f, ...)

/// <summary>
/// Logs a warning to the log file when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_WARNING(f, ...)

/// <summary>
/// Logs an error to the log file when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the log file when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_FATAL(f, ...)

#endif // AE_RELEASE

#ifdef AE_DIST

/// <summary>
/// Logs a message to the log file when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG(l, f, ...)

/// <summary>
/// Logs a trace message to the log file when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_TRACE(f, ...)

/// <summary>
/// Logs an information message to the log file when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_INFO(f, ...)

/// <summary>
/// Logs a warning to the log file when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_WARNING(f, ...)

/// <summary>
/// Logs an error to the log file when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the log file when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DEBUG_FATAL(f, ...)

/// <summary>
/// Logs a message to the log file when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE(l, f, ...)

/// <summary>
/// Logs a trace message to the log file when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_TRACE(f, ...)

/// <summary>
/// Logs an information message to the log file when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_INFO(f, ...)

/// <summary>
/// Logs a warning to the log file when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_WARNING(f, ...)

/// <summary>
/// Logs an error to the log file when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_ERROR(f, ...)

/// <summary>
/// Logs a fatal error to the log file when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_RELEASE_FATAL(f, ...)

/// <summary>
/// Logs a message to the log file when the build type is Dist.
/// </summary>
/// <param name="l">is the log_level (severity) of the message</param>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST(l, f, ...) i_ae_log_file(l, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a trace message to the log file when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_TRACE(f, ...) i_ae_log_file(TRACE, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an information message to the log file when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_INFO(f, ...) i_ae_log_file(INFO, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a warning to the log file when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_WARNING(f, ...) i_ae_log_file(WARNING, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs an error to the log file when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_ERROR(f, ...) i_ae_log_file(ERROR, I_AE_LOCATION, f, ##__VA_ARGS__)

/// <summary>
/// Logs a fatal error to the log file when the build type is Dist.
/// </summary>
/// <param name="f">is the message format as a const char*</param>
/// <param name="__VA_ARGS__">is additional arguments to be inserted</param>
#define AE_LOG_FILE_DIST_FATAL(f, ...) i_ae_log_file(FATAL, I_AE_LOCATION, f, ##__VA_ARGS__)

#endif // AE_DIST

/// <summary>
/// Internal function that should only be called through macros. (AE_LOG_FILE_NEXT_LINE_...)
/// </summary>
void i_ae_log_file_next_line();

/// <summary>
/// Logs a blank line to the log file regardless of build type.
/// </summary>
#define AE_LOG_FILE_NEXT_LINE() i_ae_log_file_next_line()

#ifdef AE_DEBUG

/// <summary>
/// Logs a blank line to the log file when the build type is Debug.
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_DEBUG() i_ae_log_file_next_line()
/// <summary>
/// Logs a blank line to the log file when the build type is Release. (Removed since build type is currently Debug)
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_RELEASE()
/// <summary>
/// Logs a blank line to the log file when the build type is Dist. (Removed since build type is currently Debug)
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_DIST()

#endif // AE_DEBUG

#ifdef AE_RELEASE

/// <summary>
/// Logs a blank line to the log file when the build type is Debug. (Removed since build type is currently Release)
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_DEBUG() 
/// <summary>
/// Logs a blank line to the log file when the build type is Release.
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_RELEASE() i_ae_log_file_next_line()
/// <summary>
/// Logs a blank line to the log file when the build type is Dist. (Removed since build type is currently Release)
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_DIST()

#endif // AE_RELEASE

#ifdef AE_DIST

/// <summary>
/// Logs a blank line to the log file when the build type is Debug. (Removed since build type is currently Dist)
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_DEBUG()
/// <summary>
/// Logs a blank line to the log file when the build type is Release. (Removed since build type is currently Dist)
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_RELEASE()
/// <summary>
/// Logs a blank line to the log file when the build type is Dist.
/// </summary>
#define AE_LOG_FILE_NEXT_LINE_DIST() i_ae_log_file_next_line()

#endif // AE_DIST
