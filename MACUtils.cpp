//---------------------------------------------------------------------------


#pragma hdrstop

#include "MACUtils.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------
CMACAddress::CMACAddress()
{
    iCount = 0;
    getMac();
}
int CMACAddress::Count()
{
    return iCount;
}

bool CMACAddress::getMac(int iIndex,TMAC& mac)
{
    if(iIndex<0 || iIndex>=10)
        return false;
    else
    {
        mac =FMAC[iIndex];
        return true;
    }
}

void CMACAddress::getMac()
{
    int AddrLen = 6;
    PIP_ADAPTER_INFO PAdapterInfo;
    DWORD ret;
    int i;
    PIP_ADAPTER_INFO Next;
    AnsiString sMAC;
    DWORD OutBufLen;

    try
    {
        GetAdaptersInfo(NULL,&OutBufLen);
        PAdapterInfo = (PIP_ADAPTER_INFO)malloc(OutBufLen);
        ret = GetAdaptersInfo(PAdapterInfo, &OutBufLen);
        if(ret==0)
        {
            Next =PAdapterInfo;
            do
            {
                sMAC = Next->Description;
                strcpy(FMAC[iCount].desc,sMAC.c_str());
                sMAC = "";
                for(i=0;i<AddrLen;i++)
                {
                    sMAC += IntToHex(Next->Address[i],2);
                    if(i!=AddrLen-1)
                        sMAC+="-";
                }
                strcpy(FMAC[iCount].mac,sMAC.c_str());
                iCount++;
                Next = Next->Next;
            }
            while(Next!=NULL);
        }
        free(PAdapterInfo);
    }
    catch(...)
    {}
}