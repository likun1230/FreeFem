/****************************************************************************/
/* This file is part of FreeFEM.                                            */
/*                                                                          */
/* FreeFEM is free software: you can redistribute it and/or modify          */
/* it under the terms of the GNU Lesser General Public License as           */
/* published by the Free Software Foundation, either version 3 of           */
/* the License, or (at your option) any later version.                      */
/*                                                                          */
/* FreeFEM is distributed in the hope that it will be useful,               */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            */
/* GNU Lesser General Public License for more details.                      */
/*                                                                          */
/* You should have received a copy of the GNU Lesser General Public License */
/* along with FreeFEM. If not, see <http://www.gnu.org/licenses/>.          */
/****************************************************************************/
// SUMMARY : ...
// LICENSE : LGPLv3
// ORG     : LJLL Universite Pierre et Marie Curie, Paris, FRANCE
// AUTHORS : ...
// E-MAIL  : ...

#ifndef _HEAP_SORT_HPP_
#define _HEAP_SORT_HPP_

template<class T>
void HeapSort(T *c, long n) {
  long l, j, r, i;
  T crit;
  if (n <= 1) return;
  l = n/2;
  r = n - 1;
  while (1) { // label 2
    if (l < 1 ) { // label 20
      crit = c[r];
      c[r--] = c[0];
      if (!r) { c[0] = crit; return; }
    } else crit = c[--l];
    j = l;
    while (1) { // label 4
      i = j;
      j = 2*j + 1;
      if (j > r) { c[i] = crit; break; } // L8 -> G2
      if ((j < r) && (c[j] < c[j+1])) j++; // L5
      if (crit < c[j]) c[i] = c[j]; // L6+1 G4
      else { c[i] = crit; break; } // L8 -> G2
    }
  }
}

template<class K, class T>
void HeapSort(K *k, T *t, long n) {
  long l, j, r, i;
  K kk;
  T tt;
  if (n <= 1) return;
  l = n/2;
  r = n - 1;
  while (1) { // label 2
    if (l < 1) { // label 20
    kk = k[r];
    tt = t[r];
    t[r] = t[0], k[r--] = k[0];
    if (!r) { k[0] = kk; t[0] = tt; return; }
    } else { kk = k[--l]; tt = t[l]; }
    j = l;
    while (1) { // label 4
    i = j;
    j = 2*j + 1;
    if (j > r) { k[i] = kk; t[i] = tt; break; } // L8 -> G2
    if ((j < r) && (k[j] < k[j+1])) j++; // L5
    if (kk < k[j]) { k[i] = k[j]; t[i] = t[j]; } // L6+1 G4
    else { k[i] = kk; t[i] = tt; break; } //L8 -> G2
    }
  }
}

#endif //_HEAP_SORT_HPP_
