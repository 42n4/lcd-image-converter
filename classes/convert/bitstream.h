/*
 * LCD Image Converter. Converts images and fonts for embedded applciations.
 * Copyright (C) 2012 riuson
 * mailto: riuson@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef BITSTREAM_H
#define BITSTREAM_H
//-----------------------------------------------------------------------------
#include <QtGlobal>
//-----------------------------------------------------------------------------
template <class T> class QVector;
//-----------------------------------------------------------------------------
class ConversionMatrix;
//-----------------------------------------------------------------------------
class BitStream
{
public:
    BitStream(ConversionMatrix *matrix, QVector<quint32> *data, int start, int count);

    void init();
    bool eof();
    quint32 next();

private:
    ConversionMatrix *mMatrix;
    QVector<quint32> *mData;
    int mStart;
    int mCount;
    int mBlockSize;

    int mCurrentPixel;
    int mMaskSource;
    int mMaskCurrent;
    int mBitsReaded;

    bool nextBit();
    // remaining bit count from one pixel
    int remain();
};
//-----------------------------------------------------------------------------
#endif // BITSTREAM_H