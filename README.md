<!--
 - Copyright (C) 2017, 2018  Internet Systems Consortium, Inc. ("ISC")
 -
 - This Source Code Form is subject to the terms of the Mozilla Public
 - License, v. 2.0. If a copy of the MPL was not distributed with this
 - file, You can obtain one at http://mozilla.org/MPL/2.0/.
-->
# BIND 9

### Contents

1. [Introduction](#intro)
1. [Reporting bugs and getting help](#help)
1. [Contributing to BIND](#contrib)
1. [BIND 9.13 features](#features)
1. [Building BIND](#build)
1. [macOS](#macos)
1. [Compile-time options](#opts)
1. [Automated testing](#testing)
1. [Documentation](#doc)
1. [Change log](#changes)
1. [Acknowledgments](#ack)

### <a name="intro"/> Introduction

BIND (Berkeley Internet Name Domain) is a complete, highly portable
implementation of the DNS (Domain Name System) protocol.

The BIND name server, `named`, is able to serve as an authoritative name
server, recursive resolver, DNS forwarder, or all three simultaneously.  It
implements views for split-horizon DNS, automatic DNSSEC zone signing and
key management, catalog zones to facilitate provisioning of zone data
throughout a name server constellation, response policy zones (RPZ) to
protect clients from malicious data, response rate limiting (RRL) and
recursive query limits to reduce distributed denial of service attacks,
and many other advanced DNS features.  BIND also includes a suite of
administrative tools, including the `dig` and `delv` DNS lookup tools,
`nsupdate` for dynamic DNS zone updates, `rndc` for remote name server
administration, and more.

BIND 9 is a complete re-write of the BIND architecture that was used in
versions 4 and 8.  Internet Systems Consortium
([https://www.isc.org](https://www.isc.org)), a 501(c)(3) public benefit
corporation dedicated to providing software and services in support of the
Internet infrastructure, developed BIND 9 and is responsible for its
ongoing maintenance and improvement.  BIND is open source software
licenced under the terms of the Mozilla Public License, version 2.0.

For a summary of features introduced in past major releases of BIND,
see the file [HISTORY](HISTORY.md).

For a detailed list of changes made throughout the history of BIND 9, see
the file [CHANGES](CHANGES). See [below](#changes) for details on the
CHANGES file format.

For up-to-date release notes and errata, see
[http://www.isc.org/software/bind9/releasenotes](http://www.isc.org/software/bind9/releasenotes)

### <a name="help"/> Reporting bugs and getting help

Please report assertion failure errors and suspected security issues to
[security-officer@isc.org](mailto:security-officer@isc.org).

General bug reports can be sent to
[bind9-bugs@isc.org](mailto:bind9-bugs@isc.org).

Feature requests can be sent to
[bind-suggest@isc.org](mailto:bind-suggest@isc.org).

Please note that, while tickets submitted to ISC's ticketing system
are not initially publicly readable by default, they can be made publicly
acessible afterward.  Please do not include information in bug reports that
you consider to be confidential. In particular, when sending the contents of
your configuration file, it is advisable to obscure key secrets: this can
be done automatically by using `named-checkconf -px`.

Professional support and training for BIND are available from
ISC at [https://www.isc.org/support](https://www.isc.org/support).

To join the __BIND Users__ mailing list, or view the archives, visit
[https://lists.isc.org/mailman/listinfo/bind-users](https://lists.isc.org/mailman/listinfo/bind-users).

If you're planning on making changes to the BIND 9 source code, you
may also want to join the __BIND Workers__ mailing list, at
[https://lists.isc.org/mailman/listinfo/bind-workers](https://lists.isc.org/mailman/listinfo/bind-workers).

### <a name="contrib"/> Contributing to BIND

ISC maintains a public git repository for BIND; details can be found
at [http://www.isc.org/git/](http://www.isc.org/git/).

Information for BIND contributors can be found in the following files:
- General information: [doc/dev/contrib.md](doc/dev/contrib.md)
- BIND 9 code style: [doc/dev/style.md](doc/dev/style.md)
- BIND architecture and developer guide: [doc/dev/dev.md](doc/dev/dev.md)

Patches for BIND may be submitted either as Github pull requests
or via email.  When submitting a patch via email, please prepend the
subject header with "`[PATCH]`" so it will be easier for us to find. 
If your patch introduces a new feature in BIND, please submit it to
[bind-suggest@isc.org](mailto:bind-suggest@isc.org); if it fixes a bug,
please submit it to [bind9-bugs@isc.org](mailto:bind9-bugs@isc.org).

### <a name="features"/> BIND 9.13 features

BIND 9.13.0 is the newest development branch of BIND 9. It includes a
number of changes from BIND 9.12 and earlier releases.  New features
include:

* TBD

### <a name="build"/> Building BIND

BIND requires a UNIX or Linux system with an ANSI C compiler, basic POSIX
support, and a 64-bit integer type. Successful builds have been observed on
many versions of Linux and UNIX, including RedHat, Fedora, Debian, Ubuntu,
SuSE, Slackware, FreeBSD, NetBSD, OpenBSD, Mac OS X, Solaris, HP-UX, AIX,
SCO OpenServer, and OpenWRT. 

BIND is also available for Windows 2008 and higher.  See
`win32utils/readme1st.txt` for details on building for Windows
systems.

To build on a UNIX or Linux system, use:

		$ ./configure
		$ make

If you're planning on making changes to the BIND 9 source, you should run
`make depend`.  If you're using Emacs, you might find `make tags` helpful.

Several environment variables that can be set before running `configure` will
affect compilation:

|Variable|Description |
|--------------------|-----------------------------------------------|
|`CC`|The C compiler to use.  `configure` tries to figure out the right one for supported systems.|
|`CFLAGS`|C compiler flags.  Defaults to include -g and/or -O2 as supported by the compiler.  Please include '-g' if you need to set `CFLAGS`. |
|`STD_CINCLUDES`|System header file directories.  Can be used to specify where add-on thread or IPv6 support is, for example.  Defaults to empty string.|
|`STD_CDEFINES`|Any additional preprocessor symbols you want defined.  Defaults to empty string. For a list of possible settings, see the file [OPTIONS](OPTIONS.md).|
|`LDFLAGS`|Linker flags. Defaults to empty string.|
|`BUILD_CC`|Needed when cross-compiling: the native C compiler to use when building for the target system.|
|`BUILD_CFLAGS`|Optional, used for cross-compiling|
|`BUILD_CPPFLAGS`||
|`BUILD_LDFLAGS`||
|`BUILD_LIBS`||

#### <a name="macos"> macOS

Building on macOS assumes that the "Command Tools for Xcode" is installed.
This can be downloaded from https://developer.apple.com/download/more/
or if you have Xcode already installed you can run "xcode-select --install".
This will add /usr/include to the system and install the compiler and other
tools so that they can be easily found.


#### <a name="opts"/> Compile-time options

To see a full list of configuration options, run `configure --help`.

On most platforms, BIND 9 is built with multithreading support, allowing it
to take advantage of multiple CPUs.  You can configure this by specifying
`--enable-threads` or `--disable-threads` on the `configure` command line.
The default is to enable threads, except on some older operating systems on
which threads are known to have had problems in the past.  (Note: Prior to
BIND 9.10, the default was to disable threads on Linux systems; this has
now been reversed.  On Linux systems, the threaded build is known to change
BIND's behavior with respect to file permissions; it may be necessary to
specify a user with the -u option when running `named`.)

To build shared libraries, specify `--with-libtool` on the `configure`
command line.

Certain compiled-in constants and default settings can be increased to
values better suited to large servers with abundant memory resources (e.g,
64-bit servers with 12G or more of memory) by specifying
`--with-tuning=large` on the `configure` command line. This can improve
performance on big servers, but will consume more memory and may degrade
performance on smaller systems.

For the server to support DNSSEC, you need to build it with crypto support.
To use OpenSSL, you should have OpenSSL 1.0.2e or newer installed.  If the
OpenSSL library is installed in a nonstandard location, specify the prefix
using "--with-openssl=&lt;PREFIX&gt;" on the configure command line. To use a
PKCS#11 hardware service module for cryptographic operations, specify the
path to the PKCS#11 provider library using "--with-pkcs11=&lt;PREFIX&gt;", and
configure BIND with "--enable-native-pkcs11".

To support the HTTP statistics channel, the server must be linked with at
least one of the following: libxml2
[http://xmlsoft.org](http://xmlsoft.org) or json-c
[https://github.com/json-c](https://github.com/json-c).  If these are
installed at a nonstandard location, specify the prefix using
`--with-libxml2=/prefix` or `--with-libjson=/prefix`.

To support compression on the HTTP statistics channel, the server must be
linked against libzlib.  If this is installed in a nonstandard location,
specify the prefix using `--with-zlib=/prefix`.

To support storing configuration data for runtime-added zones in an LMDB
database, the server must be linked with liblmdb. If this is installed in a
nonstandard location, specify the prefix using "with-lmdb=/prefix".

To support GeoIP location-based ACLs, the server must be linked with
libGeoIP. This is not turned on by default; BIND must be configured with
"--with-geoip". If the library is installed in a nonstandard location, use
specify the prefix using "--with-geoip=/prefix".

For DNSTAP packet logging, you must have installed libfstrm
[https://github.com/farsightsec/fstrm](https://github.com/farsightsec/fstrm)
and libprotobuf-c
[https://developers.google.com/protocol-buffers](https://developers.google.com/protocol-buffers),
and BIND must be configured with "--enable-dnstap".

Portions of BIND that are written in Python, including
`dnssec-keymgr`, `dnssec-coverage`, `dnssec-checkds`, and some of the
system tests, require the 'argparse' and 'ply' modules to be available.
'argparse' is a standard module as of Python 2.7 and Python 3.2.
'ply' is available from [https://pypi.python.org/pypi/ply](https://pypi.python.org/pypi/ply).

On some platforms it is necessary to explicitly request large file support
to handle files bigger than 2GB.  This can be done by using
`--enable-largefile` on the `configure` command line.

Support for the "fixed" rrset-order option can be enabled or disabled by
specifying `--enable-fixed-rrset` or `--disable-fixed-rrset` on the
configure command line.  By default, fixed rrset-order is disabled to
reduce memory footprint.

If your operating system has integrated support for IPv6, it will be used
automatically.  If you have installed KAME IPv6 separately, use
`--with-kame[=PATH]` to specify its location.

`make install` will install `named` and the various BIND 9 libraries.  By
default, installation is into /usr/local, but this can be changed with the
`--prefix` option when running `configure`.

You may specify the option `--sysconfdir` to set the directory where
configuration files like `named.conf` go by default, and `--localstatedir`
to set the default parent directory of `run/named.pid`.   For backwards
compatibility with BIND 8, `--sysconfdir` defaults to `/etc` and
`--localstatedir` defaults to `/var` if no `--prefix` option is given.  If
there is a `--prefix` option, sysconfdir defaults to `$prefix/etc` and
localstatedir defaults to `$prefix/var`.

### <a name="testing"/> Automated testing

A system test suite can be run with `make test`.  The system tests require
you to configure a set of virtual IP addresses on your system (this allows
multiple servers to run locally and communicate with one another).  These
IP addresses can be configured by running the command
`bin/tests/system/ifconfig.sh up` as root.

Some tests require Perl and the Net::DNS and/or IO::Socket::INET6 modules,
and will be skipped if these are not available. Some tests require Python
and the 'dnspython' module and will be skipped if these are not available.
See bin/tests/system/README for further details.

Unit tests are implemented using Automated Testing Framework (ATF).
To run them, use `configure --with-atf`, then run `make test` or
`make unit`.

### <a name="doc"/> Documentation

The *BIND 9 Administrator Reference Manual* is included with the source
distribution, in DocBook XML, HTML and PDF format, in the `doc/arm`
directory.

Some of the programs in the BIND 9 distribution have man pages in their
directories.  In particular, the command line options of `named` are
documented in `bin/named/named.8`.

Frequently (and not-so-frequently) asked questions and their answers
can be found in the ISC Knowledge Base at
[https://kb.isc.org](https://kb.isc.org).

Additional information on various subjects can be found in other
`README` files throughout the source tree.

### <a name="changes"/> Change log

A detailed list of all changes that have been made throughout the
development BIND 9 is included in the file CHANGES, with the most recent
changes listed first.  Change notes include tags indicating the category of
the change that was made; these categories are:

|Category	|Description	        			|
|--------------	|-----------------------------------------------|
| [func] | New feature |
| [bug] | General bug fix |
| [security] | Fix for a significant security flaw |
| [experimental] | Used for new features when the syntax or other aspects of the design are still in flux and may change |
| [port] | Portability enhancement |
| [maint] | Updates to built-in data such as root server addresses and keys |
| [tuning] | Changes to built-in configuration defaults and constants to improve performance |
| [performance] | Other changes to improve server performance |
| [protocol] | Updates to the DNS protocol such as new RR types |
| [test] | Changes to the automatic tests, not affecting server functionality |
| [cleanup] | Minor corrections and refactoring |
| [doc] | Documentation |
| [contrib] | Changes to the contributed tools and libraries in the 'contrib' subdirectory |
| [placeholder] | Used in the master development branch to reserve change numbers for use in other branches, e.g. when fixing a bug that only exists in older releases |

In general, [func] and [experimental] tags will only appear in new-feature
releases (i.e., those with version numbers ending in zero).  Some new
functionality may be backported to older releases on a case-by-case basis.
All other change types may be applied to all currently-supported releases.

### <a name="ack"/> Acknowledgments

* The original development of BIND 9 was underwritten by the
  following organizations:

		Sun Microsystems, Inc.
		Hewlett Packard
		Compaq Computer Corporation
		IBM
		Process Software Corporation
		Silicon Graphics, Inc.
		Network Associates, Inc.
		U.S. Defense Information Systems Agency
		USENIX Association
		Stichting NLnet - NLnet Foundation
		Nominum, Inc.

* This product includes software developed by the OpenSSL Project for use
  in the OpenSSL Toolkit.
  [http://www.OpenSSL.org/](http://www.OpenSSL.org/)
* This product includes cryptographic software written by Eric Young
  (eay@cryptsoft.com)
* This product includes software written by Tim Hudson (tjh@cryptsoft.com)
