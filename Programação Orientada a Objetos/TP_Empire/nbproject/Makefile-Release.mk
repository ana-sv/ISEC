#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Abandonado.o \
	${OBJECTDIR}/Alianca.o \
	${OBJECTDIR}/BancoCentral.o \
	${OBJECTDIR}/BolsaValores.o \
	${OBJECTDIR}/Castelo.o \
	${OBJECTDIR}/Continente.o \
	${OBJECTDIR}/DefesasTerritoriais.o \
	${OBJECTDIR}/DronesMilitares.o \
	${OBJECTDIR}/Duna.o \
	${OBJECTDIR}/Evento.o \
	${OBJECTDIR}/Fortaleza.o \
	${OBJECTDIR}/Ilha.o \
	${OBJECTDIR}/Imperio.o \
	${OBJECTDIR}/Inicial.o \
	${OBJECTDIR}/Invasao.o \
	${OBJECTDIR}/Jogo.o \
	${OBJECTDIR}/Mina.o \
	${OBJECTDIR}/MisseisTeleguiados.o \
	${OBJECTDIR}/Montanha.o \
	${OBJECTDIR}/Mundo.o \
	${OBJECTDIR}/Pescaria.o \
	${OBJECTDIR}/Planicie.o \
	${OBJECTDIR}/Refugio.o \
	${OBJECTDIR}/Snapshot.o \
	${OBJECTDIR}/Tecnologia.o \
	${OBJECTDIR}/Territorio.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/empire.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/empire.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/empire ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Abandonado.o: Abandonado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Abandonado.o Abandonado.cpp

${OBJECTDIR}/Alianca.o: Alianca.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Alianca.o Alianca.cpp

${OBJECTDIR}/BancoCentral.o: BancoCentral.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BancoCentral.o BancoCentral.cpp

${OBJECTDIR}/BolsaValores.o: BolsaValores.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BolsaValores.o BolsaValores.cpp

${OBJECTDIR}/Castelo.o: Castelo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Castelo.o Castelo.cpp

${OBJECTDIR}/Continente.o: Continente.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Continente.o Continente.cpp

${OBJECTDIR}/DefesasTerritoriais.o: DefesasTerritoriais.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DefesasTerritoriais.o DefesasTerritoriais.cpp

${OBJECTDIR}/DronesMilitares.o: DronesMilitares.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DronesMilitares.o DronesMilitares.cpp

${OBJECTDIR}/Duna.o: Duna.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Duna.o Duna.cpp

${OBJECTDIR}/Evento.o: Evento.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Evento.o Evento.cpp

${OBJECTDIR}/Fortaleza.o: Fortaleza.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fortaleza.o Fortaleza.cpp

${OBJECTDIR}/Ilha.o: Ilha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ilha.o Ilha.cpp

${OBJECTDIR}/Imperio.o: Imperio.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Imperio.o Imperio.cpp

${OBJECTDIR}/Inicial.o: Inicial.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Inicial.o Inicial.cpp

${OBJECTDIR}/Invasao.o: Invasao.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Invasao.o Invasao.cpp

${OBJECTDIR}/Jogo.o: Jogo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Jogo.o Jogo.cpp

${OBJECTDIR}/Mina.o: Mina.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mina.o Mina.cpp

${OBJECTDIR}/MisseisTeleguiados.o: MisseisTeleguiados.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MisseisTeleguiados.o MisseisTeleguiados.cpp

${OBJECTDIR}/Montanha.o: Montanha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Montanha.o Montanha.cpp

${OBJECTDIR}/Mundo.o: Mundo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mundo.o Mundo.cpp

${OBJECTDIR}/Pescaria.o: Pescaria.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pescaria.o Pescaria.cpp

${OBJECTDIR}/Planicie.o: Planicie.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Planicie.o Planicie.cpp

${OBJECTDIR}/Refugio.o: Refugio.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Refugio.o Refugio.cpp

${OBJECTDIR}/Snapshot.o: Snapshot.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Snapshot.o Snapshot.cpp

${OBJECTDIR}/Tecnologia.o: Tecnologia.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tecnologia.o Tecnologia.cpp

${OBJECTDIR}/Territorio.o: Territorio.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Territorio.o Territorio.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
