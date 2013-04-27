/*
 * This file is part of the wxLame and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef FRMPROGRESS_H
#define FRMPROGRESS_H

//(*Headers(frmProgress)
#include <wx/gauge.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)

#include "FileInfo.h"
#include "ConfigBase.h"

#include <wx/process.h>

enum
{
    LAME_ENCODE = 0,
    LAME_DECODE = 1,
};

class frmProgress : public wxDialog
{
public:

    frmProgress(wxWindow* parent, ConfigBase* configBase, ArrayOfFiles* lstFilesData, int workType, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
    virtual ~frmProgress();

    //(*Declarations(frmProgress)
    wxGauge* gaugeListProgress;
    wxStaticText* lblStatusFile;
    wxGauge* gaugeFileProgress;
    wxTimer Timer1;
    wxStaticText* lblStatusList;
    wxButton* btnCancel;
    //*)

protected:

    //(*Identifiers(frmProgress)
    static const long ID_STATICTEXT1;
    static const long ID_GAUGE1;
    static const long ID_STATICTEXT2;
    static const long ID_GAUGE2;
    static const long ID_BUTTON1;
    static const long ID_TIMER1;
    //*)

private:

    //(*Handlers(frmProgress)
    void OnTimer1Trigger(wxTimerEvent& event);
    void OnbtnCancelClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnClose(wxCloseEvent& event);
    //*)

    void OnIdle(wxIdleEvent& event);
    void OnProcessTerm(wxProcessEvent& event);
    void processNextFile();
    void finishedWork();
    void stringToGaugeUpdate(const wxString & inputString);
    void stringLabelsUpdate();

    ConfigBase* configBase;
    ArrayOfFiles* lstFilesData;
    wxProcess* process;
    int fileIterator;
    int workType;
    bool workingProgress;
    long processPID;
    wxString inputString;

    DECLARE_EVENT_TABLE()
};

#endif
