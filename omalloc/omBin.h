/*******************************************************************
 *  File:    omBin.h
 *  Purpose: declaration of routines related to Bins
 *  Author:  obachman (Olaf Bachmann)
 *  Created: 11/99
 *  Version: $Id: omBin.h,v 1.3 2000-08-14 12:26:41 obachman Exp $
 *******************************************************************/
#ifndef OM_BIN_H
#define OM_BIN_H



#define omGetAlignedSpecBin(size) _omGetSpecBin(size, 1, 0)
#define omGetSpecBin(size) _omGetSpecBin(size, 0, 0)
omBin _omGetSpecBin(size_t size, int align, int track);

#define omUnGetSpecBin(bin_ptr) _omUnGetSpecBin(bin_ptr, 0)
#define omDeleteSpecBin(bin_ptr) _omUnGetSpecBin(bin_ptr, 1)
void  _omUnGetSpecBin(omBin *bin, int force);
size_t omGetUsedBinBytes();

unsigned long omGetNewStickyBinTag(omBin bin);
void omSetStickyBinTag(omBin bin, unsigned long sticky);
void omUnSetStickyBinTag(omBin bin, unsigned long sticky);
void omDeleteStickyBinTag(omBin bin, unsigned long sticky);

unsigned long omGetNewStickyAllBinTag();
void omSetStickyAllBinTag(unsigned long sticky);
void omUnSetStickyAllBinTag(unsigned long sticky);
void omDeleteStickyAllBinTag(unsigned long sticky);

void omPrintBinStats(FILE* fd);

/*BEGINPRIVATE*/
#ifdef OM_HAVE_TRACK
#define omGetSpecTrackBin(size) _omGetSpecBin(size, 0, 1)
#endif

#define omIsStaticNormalBin(bin)                                            \
 ((unsigned long) bin >= ((unsigned long) &om_StaticBin[0]) &&              \
  (unsigned long) bin <= ((unsigned long) &om_StaticBin[OM_MAX_BIN_INDEX]))
#define omIsNormalBin(bin) omIsStaticNormalBin(bin) || omFindInGList(om_SpecBin, next, bin, bin)

#ifdef OM_HAVE_TRACK
#define omIsStaticTrackBin(bin)                                                  \
 ((unsigned long) bin >= ((unsigned long) &om_StaticTrackBin[0]) &&              \
  (unsigned long) bin <= ((unsigned long) &om_StaticTrackBin[OM_MAX_BIN_INDEX]))
#define omIsTrackBin(bin) omIsStaticTrackBin(bin) || omFindInGList(om_SpecTrackBin, next, bin, bin)
#else
#define omIsStaticTrackBin(bin) 0
#define omIsTrackBin(bin)       0
#endif
#define omIsStaticBin(bin) omIsStaticNormalBin(bin) || omIsStaticTrackBin(bin)
/*ENDPRIVATE*/

#endif /* OM_BIN_H */

