DESCRIPTION = "Standalone web server written in C# that can be used to run ASP.NET applications"
SECTION = "devel/mono"
DEPENDS = "mono"
RDEPENDS_${PN} = "mono"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=9e1603e27acd337015fdfa7f7ff936c7"

inherit autotools-brokensep

SRC_URI = "https://github.com/mono/xsp/archive/${PV}.tar.gz"

S = "${WORKDIR}/xsp-${PV}"

PACKAGES += "${PN}-test \
	${PN}-unittest \
"

FILES_${PN}-test = "${libdir}/xsp/test/*"

FILES_${PN}-unittest = "${libdir}/xsp/unittests/*"

FILES_${PN}-doc += "${libdir}/monodoc/*"

# AJL - For now we are going to parcel up the different XSP hosting (mod_mono, fastcgi, xsp) together. More granular packages in future
FILES_${PN} = "${bindir}/* \
	${libdir}/mono/* \
	${libdir}/xsp/2.0/* \
	${libdir}/xsp/4.0/* \
"

# We seem to run into problems with make parallelisation building mono-xsp, so disable it for now
PARALLEL_MAKE = ""