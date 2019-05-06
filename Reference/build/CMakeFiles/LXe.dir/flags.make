# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# compile CXX with /usr/bin/c++
CXX_FLAGS = -W -Wall -pedantic -Wno-non-virtual-dtor -Wno-long-long -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-variadic-macros -Wshadow -pipe -std=c++98  -g -DG4FPE_DEBUG -g  

CXX_DEFINES = -DG4INTY_USE_QT -DG4INTY_USE_XT -DG4UI_USE -DG4UI_USE_QT -DG4UI_USE_TCSH -DG4VERBOSE -DG4VIS_USE -DG4VIS_USE_OPENGL -DG4VIS_USE_OPENGLQT -DG4VIS_USE_OPENGLX -DG4_STORE_TRAJECTORY

CXX_INCLUDES = -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/analysis/g4tools/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/analysis/csv/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/analysis/hntools/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/analysis/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/analysis/root/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/analysis/xml/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/digits_hits/detector/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/digits_hits/digits/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/digits_hits/hits/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/digits_hits/scorer/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/digits_hits/utils/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/error_propagation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/event/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/externals/clhep/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/externals/zlib/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/biasing/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/divisions/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/magneticfield/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/navigation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/solids/Boolean/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/solids/CSG/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/solids/specific/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/solids/usolids/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/geometry/volumes/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/global/HEPGeometry/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/global/HEPNumerics/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/global/HEPRandom/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/global/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/graphics_reps/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/intercoms/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/interfaces/GAG/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/interfaces/basic/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/interfaces/common/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/materials/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/parameterisations/gflash/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/adjoint/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/bosons/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/hadrons/barions/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/hadrons/ions/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/hadrons/mesons/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/leptons/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/shortlived/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/particles/utils/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/persistency/ascii/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/persistency/mctruth/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/builders/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/decay/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/electromagnetic/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/factory/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/gamma_lepto_nuclear/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/hadron_elastic/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/hadron_inelastic/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/ions/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/limiters/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/constructors/stopping/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/lists/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/physics_lists/util/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/biasing/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/biasing/generic/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/biasing/importance/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/cuts/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/decay/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/adjoint/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/dna/processes/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/dna/models/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/dna/utils/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/dna/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/dna/molecules/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/dna/molecules/types/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/highenergy/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/lowenergy/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/muons/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/pii/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/polarisation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/standard/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/utils/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/electromagnetic/xrays/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/cross_sections/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/abla/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/abrasion/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/binary_cascade/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/cascade/cascade/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/coherent_elastic/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/ablation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/evaporation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/fermi_breakup/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/fission/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/gem_evaporation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/handler/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/multifragmentation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/photon_evaporation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/de_excitation/util/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/em_dissociation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/fission/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/im_r_matrix/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/inclxx/utils/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/inclxx/incl_physics/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/inclxx/interface/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/lend/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/lepto_nuclear/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/neutron_hp/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/parton_string/diffraction/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/parton_string/hadronization/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/parton_string/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/parton_string/qgsm/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/pre_equilibrium/exciton_model/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/qmd/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/radioactive_decay/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/quasi_elastic/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/rpg/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/theo_high_energy/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/models/util/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/processes/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/stopping/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/hadronic/util/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/optical/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/phonon/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/parameterisation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/scoring/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/processes/transportation/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/readout/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/run/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/track/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/tracking/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/FukuiRenderer/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/HepRep/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/RayTracer/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/Tree/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/VRML/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/XXX/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/externals/gl2ps/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/gMocren/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/management/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/modeling/include -I/home/galgoczi/Downloads/geant4.10.00.p04/geant4.10.00.p04/source/visualization/OpenGL/include -I/usr/include/qt4 -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/home/galgoczi/cubesat/Reference/include 

