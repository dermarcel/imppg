/*
ImPPG (Image Post-Processor) - common operations for astronomical stacks and other images
Copyright (C) 2016-2017 Filip Szczerek <ga.software@yahoo.com>

This file is part of ImPPG.

ImPPG is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ImPPG is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ImPPG.  If not, see <http://www.gnu.org/licenses/>.

File description:
    Application configuration getters/setters header.
*/

#ifndef IMPPG_APPCONFIG_H
#define IMPPG_APPCONFIG_H

#include <wx/arrstr.h>
#include <wx/fileconf.h>
#include <wx/gdicmn.h>
#include "common.h"
#include "formats.h"


namespace Configuration
{
    /// Default maximum frequency (in Hz) of issuing new processing requests by the tone curve editor and numerical control sliders (0 means: no limit)
    const int DEFAULT_MAX_PROCESSING_REQUESTS_PER_SEC = 30;

    /// Max number of items in the most recently used list of processing settings files
    const size_t MAX_MRU_SETTINGS_ITEMS = 16;

    const wxString USE_DEFAULT_SYS_LANG = "default";

    const unsigned DEFAULT_TOOL_ICON_SIZE = 32;

    /// Number of tone curve and histogram segments to draw
    const unsigned DEFAULT_TONE_CURVE_EDITOR_NUM_DRAW_SEGMENTS = 512;

    void Initialize(wxFileConfig *appConfig);

    /// Returns maximum frequency (in Hz) of issuing new processing requests by the tone curve editor and numerical control sliders (0 means: no limit)
    int GetMaxProcessingRequestsPerSec();

    /// Returns a list of the most recently used saved/loaded settings files
    wxArrayString GetMruSettings();
    void StoreMruSettings(const wxArrayString &settings);
    void EmptyMruList();

    extern c_Property<wxString> FileOpenPath;
    extern c_Property<wxString> FileSavePath;
    extern c_Property<bool>     MainWindowMaximized;
    extern c_Property<wxRect>   MainWindowPosSize;
    extern c_Property<wxRect>   ToneCurveEditorPosSize;
    extern c_Property<bool>     ToneCurveEditorVisible;
    extern c_Property<wxString> LoadSettingsPath;
    extern c_Property<wxString> SaveSettingsPath;
    extern c_Property<wxString> BatchFileOpenPath;
    extern c_Property<wxString> BatchLoadSettingsPath;
    extern c_Property<wxString> BatchOutputPath;
    extern c_Property<wxRect>   BatchDialogPosSize;
    extern c_Property<wxRect>   BatchProgressDialogPosSize;
    extern c_Property<wxRect>   AlignProgressDialogPosSize;
    extern c_Property<wxString> AlignInputPath;
    extern c_Property<wxString> AlignOutputPath;
    extern c_Property<wxRect>   AlignParamsDialogPosSize;
    /// Code of UI language to use or an empty string (then the system default will used)
    extern c_Property<wxString> UiLanguage;
    extern c_Property<bool>     LogHistogram;
    extern c_Property<OutputFormat_t> BatchOutputFormat;
    extern c_Property<int>      ProcessingPanelWidth;
    extern c_Property<unsigned> ToolIconSize;

    /// If zero, draw 1 segment per pixel
    /** NOTE: drawing 1 segment per pixel may be slow for large widths of the tone curve editor window
        (e.g. on a 3840x2160 display). */
    extern c_Property<unsigned> ToneCurveEditorNumDrawSegments;
}

#endif