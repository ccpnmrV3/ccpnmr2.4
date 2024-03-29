/*
======================COPYRIGHT/LICENSE START==========================

dist_constraint_list.h: Part of the CcpNmr Analysis program

Copyright (C) 2005 Wayne Boucher and Tim Stevens (University of Cambridge)

=======================================================================

This file contains reserved and/or proprietary information
belonging to the author and/or organisation holding the copyright.
It may not be used, distributed, modified, transmitted, stored,
or in any way accessed, except by members or employees of the CCPN,
and by these people only until 31 December 2005 and in accordance with
the guidelines of the CCPN.
 
A copy of this license can be found in ../../../license/CCPN.license.

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
#ifndef _incl_dist_constraint_list
#define _incl_dist_constraint_list

#include "dist_constraint.h"

typedef struct Dist_constraint_list
{
    int ndist_constraints;
    int ndist_constraints_alloc;
    Dist_constraint *dist_constraints;
}   *Dist_constraint_list;

extern Dist_constraint_list new_dist_constraint_list(int nconstraints,
		int *natom_pairs, int **atoms0, int **atoms1,
		float *dist_lower, float *dist_upper);

extern void delete_dist_constraint_list(Dist_constraint_list dist_constraint_list);

extern void clear_dist_constraint_list(Dist_constraint_list dist_constraint_list);

extern CcpnStatus add_dist_constraint_list(Dist_constraint_list dist_constraint_list,
	int natom_pairs, int *atoms0, int *atoms1,
	float dist_lower, float dist_upper, CcpnString error_msg);

extern CcpnStatus append_dist_constraint_list(Dist_constraint_list dist_constraint_list,
				Dist_constraint dist_constraint, CcpnString error_msg);

#endif /* _incl_dist_constraint_list */
