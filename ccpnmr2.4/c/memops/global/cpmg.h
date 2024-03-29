/*
======================COPYRIGHT/LICENSE START==========================

cpmg.h: Part of the CcpNmr Analysis program

Copyright (C) 2003-2010 Wayne Boucher and Tim Stevens (University of Cambridge)

=======================================================================

The CCPN license can be found in ../../../license/CCPN.license.

======================COPYRIGHT/LICENSE END============================

for further information, please contact :

- CCPN website (http://www.ccpn.ac.uk/)

- email: ccpn@bioc.cam.ac.uk

- contact the authors: wb104@bioc.cam.ac.uk, tjs23@cam.ac.uk
=======================================================================

If you are using this software for academic purposes, we suggest
quoting the following references:

===========================REFERENCE START=============================
R. Fogh, J. Ionides, E. Ulrich, W. Boucher, W. Vranken, J.P. Linge, M.
Habeck, W. Rieping, T.N. Bhat, J. Westbrook, K. Henrick, G. Gilliland,
H. Berman, J. Thornton, M. Nilges, J. Markley and E. Laue (2002). The
CCPN project: An interim report on a data model for the NMR community
(Progress report). Nature Struct. Biol. 9, 416-418.

Wim F. Vranken, Wayne Boucher, Tim J. Stevens, Rasmus
H. Fogh, Anne Pajon, Miguel Llinas, Eldon L. Ulrich, John L. Markley, John
Ionides and Ernest D. Laue (2005). The CCPN Data Model for NMR Spectroscopy:
Development of a Software Pipeline. Proteins 59, 687 - 696.

===========================REFERENCE END===============================

*/
#ifndef _incl_cpmg
#define _incl_cpmg

#include "macros.h"
#include "types.h"

#ifdef WIN32
extern double acosh(double x);
#endif

extern float cpmg3(float x, float *params);

extern void cpmg3_fast_init_params(int n, float *x, float *y, float *params_fit);

extern void cpmg3_slow_init_params(int n, float *x, float *y, float *params_fit);

extern float cpmg4(float x, float *params);

extern void cpmg4_fast_init_params(int n, float *x, float *y, float *params_fit);

extern void cpmg4_slow_init_params(int n, float *x, float *y, float *params_fit);

#endif /* _incl_cpmg */
