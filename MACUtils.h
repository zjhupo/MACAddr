//---------------------------------------------------------------------------

/*
  ��ȡ�������������������ַ
  ���ߣ�����
  ���ڣ�2007-5-27
  ���ã�Ҫ��IphlpApi.lib�ļ�����
*/
#ifndef MACUtilsH
#define MACUtilsH
#include <vcl.h>
#include <Iphlpapi.h>
//---------------------------------------------------------------------------
struct TMAC
{
    char mac[20];
    char desc[150];
};

class CMACAddress
{
private:
    int iCount;
    TMAC FMAC[10];
    void getMac();
public:
    CMACAddress();
    int Count();
    bool getMac(int iIndex,TMAC& mac);
};
#endif