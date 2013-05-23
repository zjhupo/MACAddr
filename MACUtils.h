//---------------------------------------------------------------------------

/*
  获取本机的所有网卡物理地址
  作者：胡泊
  日期：2007-5-27
  引用：要将IphlpApi.lib文件引入
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