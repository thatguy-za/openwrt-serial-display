#!/bin/sh

hostname=$(uci get system.@system[0].hostname)
wan_ip=$(. /lib/functions/network.sh; network_find_wan NET_IF; network_get_ipaddr NET_ADDR "${NET_IF}"; echo "${NET_ADDR}")
lan_ip=$(uci get network.lan.ipaddr)
wifi_strength=$(cat /proc/net/wireless | awk 'NR==3 {print $4}' | sed 's/\.//')

echo $hostname "|" WAN IP: $wan_ip "|" LAN IP $lan_ip "|" WAN WiFi: $wifi_strength dbm > /dev/ttyAMA0
