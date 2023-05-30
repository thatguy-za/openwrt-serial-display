#!/bin/sh

hostname=$(uci get system.@system[0].hostname)
wan_ip=$(. /lib/functions/network.sh; network_find_wan NET_IF; network_get_ipaddr NET_ADDR "${NET_IF}"; echo "${NET_ADDR}")
lan_ip=$(uci get network.lan.ipaddr)
wifi_strength=$(cat /proc/net/wireless | awk 'NR==3 {print $4}' | sed 's/\.//')
let cpu_temp=$(cat /sys/class/thermal/thermal_zone0/temp)/1000

echo $hostname "|" WAN:$wan_ip "|" LAN:$lan_ip "|" WAN:$wifi_strength dbm CPU:$cpu_temp c > /dev/ttyAMA0
