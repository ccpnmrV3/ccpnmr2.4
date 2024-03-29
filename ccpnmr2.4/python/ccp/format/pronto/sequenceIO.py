#!/usr/bin/python

"""
======================COPYRIGHT/LICENSE START==========================

sequenceIO.py: I/O for Pronto sequence files (from chemical shift list)

Copyright (C) 2005 Wim Vranken (European Bioinformatics Institute)

=======================================================================

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
 
A copy of this license can be found in ../../../../license/LGPL.license
 
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA


======================COPYRIGHT/LICENSE END============================

for further information, please contact :

- CCPN website (http://www.ccpn.ac.uk/)
- PDBe website (http://www.ebi.ac.uk/pdbe/)

- contact Wim Vranken (wim@ebi.ac.uk)
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
"""

import os, string

# Import general functions
from memops.universal.Util import returnInt
from ccp.format.pronto.generalIO import ProntoGenericFile
from ccp.format.pronto.chemShiftsIO import ProntoChemShiftFile
from memops.universal.Io import getTopDirectory

from ccp.format.general.formatIO import Sequence, SequenceElement, SpinSystem

#####################
# Class definitions #
#####################
      
class ProntoSequenceFile(ProntoGenericFile):
  """
  Information on file level
  """
  def initialize(self):
    self.sequences = []

  def read(self,verbose = 0):

    fin = open(self.name, 'rU')

    # Read, look for first line
    line = fin.readline()

    cols = string.split(line)
    
    if cols[0] == 'Spin' and cols[1] == 'system':

      if verbose == 1:
        print "Reading Pronto sequence from chemical shift file %s" % self.name

      self.sequences.append(ProntoSequence())
      fin.close()
      
      csFile = ProntoChemShiftFile(name = self.name)
      csFile.read()
      
      seqCode = 999999
      
      for cs in csFile.chemShifts:
      
        if seqCode != cs.seqCode:
        
          seqCode = cs.seqCode
        
          if cs.resLabel != None:
            
            #
            # Make sure it's sequential...
            #
            
            if self.sequences[-1].elements and seqCode != self.sequences[-1].elements[-1].seqCode + 1:
              
              for tempSeqCode in range(self.sequences[-1].elements[-1].seqCode + 1,seqCode):
              
                self.sequences[-1].elements.append(ProntoSequenceElement(tempSeqCode,'XXX'))
            
            self.sequences[-1].elements.append(ProntoSequenceElement(seqCode,cs.resLabel))
            
          else:
            self.sequences[-1].spinSystems.append(ProntoSpinSystem(seqCode))

    else:
    
      print "File not recogized... aborting."

  def write(self,verbose = 0):

    print "Pronto sequence writing not available - try writing chemical shift file"

#
# Casting here for imports in ccpnmr.format.converters
#

class ProntoSequence(Sequence):

  def setFormatSpecific(self,*args,**keywds):
  
    self.spinSystems = []

ProntoSequenceElement = SequenceElement
ProntoSpinSystem = SpinSystem
  
###################
# Main of program #
###################

if __name__ == "__main__":  
                                                      
  files = [['../reference/pronto/spin40','local/cs.test1'],
           ['../reference/pronto/cslist.report','local/cs.test2']
          ]

  for (inFile,outFile) in files:
    
    sequenceFile = ProntoSequenceFile(os.path.join(getTopDirectory(),inFile))

    sequenceFile.read(verbose = 1)
  
    for seq in sequenceFile.sequences:
      for el in seq.elements:
        print el.seqCode, el.code3Letter
      for ss in seq.spinSystems:
        print ss.code
