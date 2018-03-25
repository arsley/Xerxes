# Xerxes

[![Build Status](https://travis-ci.org/sepehrdaddev/Xerxes.svg?branch=master)](https://travis-ci.org/sepehrdaddev/Xerxes)
[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

Xerxes Dos Tool Rewritten in C++

## Usage
`Usage: ./Xerxes <website> <port> <threads> <connections> <options>`\
Options:\
&emsp;&emsp;&emsp;&emsp;&emsp;-h&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;set attack vector to HTTP\
&emsp;&emsp;&emsp;&emsp;&emsp;-nu&emsp;&emsp;&emsp;&emsp;&emsp;set attack vector to NULLUDP\
&emsp;&emsp;&emsp;&emsp;&emsp;-nt&emsp;&emsp;&emsp;&emsp;&emsp;set attack vector to NULLTCP\
&emsp;&emsp;&emsp;&emsp;&emsp;-ft&emsp;&emsp;&emsp;&emsp;&emsp;set attack vector to TCPFlood\
&emsp;&emsp;&emsp;&emsp;&emsp;-fu&emsp;&emsp;&emsp;&emsp;&emsp;set attack vector to UDPFlood\
&emsp;&emsp;&emsp;&emsp;&emsp;-s&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;set attack vector to Slowloris\
&emsp;&emsp;&emsp;&emsp;&emsp;-ss&emsp;&emsp;&emsp;&emsp;&emsp;enable SSL\
&emsp;&emsp;&emsp;&emsp;&emsp;-w&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;wait for hosts response\
&emsp;&emsp;&emsp;&emsp;&emsp;-rh&emsp;&emsp;&emsp;&emsp;&emsp;randomize HTTP Header\
&emsp;&emsp;&emsp;&emsp;&emsp;-ru&emsp;&emsp;&emsp;&emsp;&emsp;randomize HTTP UserAgent\
&emsp;&emsp;&emsp;&emsp;&emsp;-qq&emsp;&emsp;&emsp;&emsp;&emsp;set verbosity to quiet quiet\
&emsp;&emsp;&emsp;&emsp;&emsp;-q&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;set verbosity to quiet\
&emsp;&emsp;&emsp;&emsp;&emsp;-v&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;set verbosity to verbose\
&emsp;&emsp;&emsp;&emsp;&emsp;-vv&emsp;&emsp;&emsp;&emsp;&emsp;set verbosity to very verbose

## Todo
<ul>
    <li>Add spoofed ICMP packets support</li>
    <li>Add Smurf Attack vector</li>
    <li>Add more attack vectors</li>
</ul>

## License
This software is distributed under the GNU General Public License version 3 (GPLv3)

## LEGAL NOTICE
THIS SOFTWARE IS PROVIDED FOR EDUCATIONAL USE ONLY! IF YOU ENGAGE IN ANY ILLEGAL ACTIVITY THE AUTHOR DOES NOT TAKE ANY RESPONSIBILITY FOR IT. BY USING THIS SOFTWARE YOU AGREE WITH THESE TERMS.