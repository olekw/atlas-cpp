// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright 2000-2001 Stefanus Du Toit and Aloril.
// Copyright 2001-2004 Al Riddoch.
// Automatically generated using gen_cpp.py.

#ifndef ATLAS_OBJECTS_DECODER_H
#define ATLAS_OBJECTS_DECODER_H


#include <Atlas/Message/DecoderBase.h>

namespace Atlas { namespace Objects { 

template <class T> class SmartPtr;
class RootData;
typedef SmartPtr<RootData> Root;

/** Objects hierarchy decoder
 *
 * This decoder can be bound to a codec, will assemble incoming messages,
 * check their type, convert them into the appropriate instance in the
 * Objects hierarchy and call the relevant member functions, which
 * subclasses can conveniently override to pick up the object.
 *
 * @see Atlas::Objects::Encoder
 * @author Stefanus Du Toit <sdt@gmx.net>
 */
class ObjectsDecoder : public Atlas::Message::DecoderBase
{
public:
    /// Default destructor.
    virtual ~ObjectsDecoder();
protected:
    /// Overridden by Objects::Decoder to retrieve the object.
    virtual void messageArrived(const Atlas::Message::MapType&);

    /// An unknown object has arrived.
    virtual void unknownMessageArrived(const Atlas::Message::Element&);

    /// call right object*Arrived method
    virtual void objectArrived(const Root& obj) = 0;

};

} } // namespace Atlas::Objects

#endif // ATLAS_OBJECTS_DECODER_H
