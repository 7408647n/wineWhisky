/* WINE iphlpapi.h
 * Copyright (C) 2003 Juan Lang
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */
#ifndef WINE_IPHLPAPI_H__
#define WINE_IPHLPAPI_H__

#include "wine/winheader_enter.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <iprtrmib.h>
#include <ipexport.h>
#include <iptypes.h>
#include <tcpestats.h>

#ifndef IPHLPAPI_DLL_LINKAGE
#define IPHLPAPI_DLL_LINKAGE DECLSPEC_IMPORT
#endif

#define NET_STRING_IPV4_ADDRESS           0x00000001
#define NET_STRING_IPV4_SERVICE           0x00000002
#define NET_STRING_IPV4_NETWORK           0x00000004
#define NET_STRING_IPV6_ADDRESS           0x00000008
#define NET_STRING_IPV6_ADDRESS_NO_SCOPE  0x00000010
#define NET_STRING_IPV6_SERVICE           0x00000020
#define NET_STRING_IPV6_SERVICE_NO_SCOPE  0x00000040
#define NET_STRING_IPV6_NETWORK           0x00000080
#define NET_STRING_NAMED_ADDRESS          0x00000100
#define NET_STRING_NAMED_SERVICE          0x00000200
#define NET_STRING_IP_ADDRESS (NET_STRING_IPV4_ADDRESS|NET_STRING_IPV6_ADDRESS)
#define NET_STRING_IP_ADDRESS_NO_SCOPE (NET_STRING_IPV4_ADDRESS|NET_STRING_IPV6_ADDRESS_NO_SCOPE)
#define NET_STRING_IP_SERVICE (NET_STRING_IPV4_SERVICE|NET_STRING_IPV6_SERVICE)
#define NET_STRING_IP_SERVICE_NO_SCOPE (NET_STRING_IPV4_SERVICE|NET_STRING_IPV6_SERVICE_NO_SCOPE)
#define NET_STRING_IP_NETWORK (NET_STRING_IPV4_NETWORK|NET_STRING_IPV6_NETWORK)
#define NET_STRING_ANY_ADDRESS (NET_STRING_NAMED_ADDRESS|NET_STRING_IP_ADDRESS)
#define NET_STRING_ANY_ADDRESS_NO_SCOPE (NET_STRING_NAMED_ADDRESS|NET_STRING_IP_ADDRESS_NO_SCOPE)
#define NET_STRING_ANY_SERVICE (NET_STRING_NAMED_SERVICE|NET_STRING_IP_SERVICE)
#define NET_STRING_ANY_SERVICE_NO_SCOPE (NET_STRING_NAMED_SERVICE|NET_STRING_IP_SERVICE_NO_SCOPE)

IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetExtendedTcpTable(PVOID pTcpTable, PDWORD pdwSize, BOOL bOrder, ULONG ulAf, TCP_TABLE_CLASS TableClass, ULONG Reserved);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetExtendedUdpTable(PVOID pUdpTable, PDWORD pdwSize, BOOL bOrder, ULONG ulAf, UDP_TABLE_CLASS TableClass, ULONG Reserved);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetNumberOfInterfaces(PDWORD pdwNumIf);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIfEntry(PMIB_IFROW pIfRow);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIfTable(PMIB_IFTABLE pIfTable, PULONG pdwSize, BOOL bOrder);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIpAddrTable(PMIB_IPADDRTABLE pIpAddrTable, PULONG pdwSize, BOOL bOrder);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIpNetTable(PMIB_IPNETTABLE pIpNetTable, PULONG pdwSize, BOOL bOrder);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIpForwardTable(PMIB_IPFORWARDTABLE pIpForwardTable, PULONG pdwSize, BOOL bOrder);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetTcpTable(PMIB_TCPTABLE pTcpTable, PDWORD pdwSize, BOOL bOrder);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetUdpTable(PMIB_UDPTABLE pUdpTable, PDWORD pdwSize, BOOL bOrder);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetUdp6Table(PMIB_UDP6TABLE pUdpTable, PDWORD pdwSize, BOOL bOrder);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIpStatistics(PMIB_IPSTATS pStats);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIpStatisticsEx(PMIB_IPSTATS pStats, DWORD dwFamily);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIcmpStatistics(PMIB_ICMP pStats);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetIcmpStatisticsEx(PMIB_ICMP_EX pStats, DWORD dwFamily);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetTcpStatistics(PMIB_TCPSTATS pStats);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetTcpStatisticsEx(PMIB_TCPSTATS pStats, DWORD dwFamily);
IPHLPAPI_DLL_LINKAGE ULONG WINAPI GetPerTcpConnectionEStats(MIB_TCPROW *row, TCP_ESTATS_TYPE stats, UCHAR *rw, ULONG rw_version,
                                                            ULONG rw_size, UCHAR *ro_static, ULONG ro_static_version,
                                                            ULONG ro_static_size, UCHAR *ro_dynamic, ULONG ro_dynamic_version,
                                                            ULONG ro_dynamic_size);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetUdpStatistics(PMIB_UDPSTATS pStats);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetUdpStatisticsEx(PMIB_UDPSTATS pStats, DWORD dwFamily);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SetIfEntry(PMIB_IFROW pIfRow);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI CreateIpForwardEntry(PMIB_IPFORWARDROW pRoute);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SetIpForwardEntry(PMIB_IPFORWARDROW pRoute);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI DeleteIpForwardEntry(PMIB_IPFORWARDROW pRoute);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SetIpStatistics(PMIB_IPSTATS pIpStats);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SetPerTcpConnectionEStats(MIB_TCPROW *row, TCP_ESTATS_TYPE state, BYTE *rw, ULONG version, ULONG size, ULONG offset);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SetIpTTL(UINT nTTL);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI CreateIpNetEntry(PMIB_IPNETROW pArpEntry);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SetIpNetEntry(PMIB_IPNETROW pArpEntry);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI DeleteIpNetEntry(PMIB_IPNETROW pArpEntry);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI FlushIpNetTable(DWORD dwIfIndex);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI CreateProxyArpEntry(DWORD dwAddress, DWORD dwMask, DWORD dwIfIndex);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI DeleteProxyArpEntry(DWORD dwAddress, DWORD dwMask, DWORD dwIfIndex);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SetTcpEntry(PMIB_TCPROW pTcpRow);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetInterfaceInfo(PIP_INTERFACE_INFO pIfTable, PULONG dwOutBufLen);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetUniDirectionalAdapterInfo(PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS pIPIfInfo, PULONG dwOutBufLen);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetBestInterface(IPAddr dwDestAddr, PDWORD pdwBestIfIndex);

#ifdef __WINE_WINSOCKAPI_STDLIB_H
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetBestInterfaceEx(
#ifdef USE_WS_PREFIX
    struct WS_sockaddr *pDestAddr,
#else
    struct sockaddr *pDestAddr,
#endif
    PDWORD pdwBestIfIndex);
#endif

IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetBestRoute(DWORD dwDestAddr, DWORD dwSourceAddr, PMIB_IPFORWARDROW pBestRoute);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI NotifyAddrChange(PHANDLE Handle, LPOVERLAPPED overlapped);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI NotifyRouteChange(PHANDLE Handle, LPOVERLAPPED overlapped);
IPHLPAPI_DLL_LINKAGE BOOL WINAPI CancelIPChangeNotify(LPOVERLAPPED overlapped);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetAdapterIndex(IN LPWSTR AdapterName, OUT PULONG IfIndex);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI AddIPAddress(IPAddr Address, IPMask IpMask, DWORD IfIndex, PULONG NTEContext, PULONG NTEInstance);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI DeleteIPAddress(ULONG NTEContext);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetNetworkParams(PFIXED_INFO pFixedInfo, PULONG pOutBufLen);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetAdaptersInfo(PIP_ADAPTER_INFO pAdapterInfo, PULONG pOutBufLen);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetPerAdapterInfo(ULONG IfIndex, PIP_PER_ADAPTER_INFO pPerAdapterInfo, PULONG pOutBufLen);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI IpReleaseAddress(PIP_ADAPTER_INDEX_MAP AdapterInfo);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI IpRenewAddress(PIP_ADAPTER_INDEX_MAP AdapterInfo);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI SendARP(IPAddr DestIP, IPAddr SrcIP, PULONG pMacAddr, PULONG  PhyAddrLen);
IPHLPAPI_DLL_LINKAGE BOOL WINAPI GetRTTAndHopCount(IPAddr DestIpAddress, PULONG HopCount, ULONG  MaxHops, PULONG RTT);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI GetFriendlyIfIndex(DWORD IfIndex);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI EnableRouter(HANDLE* pHandle, OVERLAPPED* pOverlapped);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI UnenableRouter(OVERLAPPED* pOverlapped, LPDWORD lpdwEnableCount);

#ifdef _WINSOCK2API_
IPHLPAPI_DLL_LINKAGE ULONG WINAPI GetAdaptersAddresses(ULONG family, ULONG flags, PVOID reserved,
                                                       PIP_ADAPTER_ADDRESSES aa, PULONG buflen);
#endif

IPHLPAPI_DLL_LINKAGE DWORD WINAPI AllocateAndGetUdpTableFromStack(PMIB_UDPTABLE *ppUdpTable, BOOL bOrder, HANDLE heap, DWORD flags);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI AllocateAndGetTcpTableFromStack(PMIB_TCPTABLE *ppTcpTable, BOOL bOrder, HANDLE heap, DWORD flags);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI AllocateAndGetTcpExTableFromStack(VOID **ppTcpTable, BOOL bOrder, HANDLE heap, DWORD flags, DWORD family);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI AllocateAndGetIpNetTableFromStack(PMIB_IPNETTABLE *ppIpNetTable, BOOL bOrder, HANDLE heap, DWORD flags);
IPHLPAPI_DLL_LINKAGE DWORD WINAPI AllocateAndGetIpForwardTableFromStack(PMIB_IPFORWARDTABLE *ppIpForwardTable, BOOL bOrder, HANDLE heap, DWORD flags);

typedef enum NET_ADDRESS_FORMAT_ {
    NET_ADDRESS_FORMAT_UNSPECIFIED,
    NET_ADDRESS_DNS_NAME,
    NET_ADDRESS_IPV4,
    NET_ADDRESS_IPV6,
} NET_ADDRESS_FORMAT;

#ifdef __WINE_WINDNS_H

typedef struct NET_ADDRESS_INFO_
{
    NET_ADDRESS_FORMAT Format;
    union
    {
        struct
        {
            WCHAR Address[DNS_MAX_NAME_BUFFER_LENGTH];
            WCHAR Port[6];
        } NamedAddress;
        SOCKADDR_IN Ipv4Address;
        SOCKADDR_IN6 Ipv6Address;
        SOCKADDR IpAddress;
    } DUMMYUNIONNAME;
} NET_ADDRESS_INFO, *PNET_ADDRESS_INFO;

#endif /* __WINE_WINDNS_H */

#ifdef __cplusplus
}
#endif

#include "wine/winheader_exit.h"

#endif /* WINE_IPHLPAPI_H__ */
