//
// Generated file, do not edit! Created by opp_msgc 4.2 from datalinklayer/EthernetFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "EthernetFrame_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(EthernetFrame);

EthernetFrame::EthernetFrame(const char *name, int kind) : cPacket(name,kind)
{
    for (unsigned int i=0; i<7; i++)
        this->Preamble_var[i] = 0;
    for (unsigned int i=0; i<1; i++)
        this->SFD_var[i] = 0;
    for (unsigned int i=0; i<6; i++)
        this->MACaddr_var[i] = 0;
    for (unsigned int i=0; i<6; i++)
        this->MACsrc_var[i] = 0;
    for (unsigned int i=0; i<4; i++)
        this->FCS_var[i] = 0;
}

EthernetFrame::EthernetFrame(const EthernetFrame& other) : cPacket(other)
{
    copy(other);
}

EthernetFrame::~EthernetFrame()
{
}

EthernetFrame& EthernetFrame::operator=(const EthernetFrame& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void EthernetFrame::copy(const EthernetFrame& other)
{
    for (unsigned int i=0; i<7; i++)
        this->Preamble_var[i] = other.Preamble_var[i];
    for (unsigned int i=0; i<1; i++)
        this->SFD_var[i] = other.SFD_var[i];
    for (unsigned int i=0; i<6; i++)
        this->MACaddr_var[i] = other.MACaddr_var[i];
    for (unsigned int i=0; i<6; i++)
        this->MACsrc_var[i] = other.MACsrc_var[i];
    for (unsigned int i=0; i<4; i++)
        this->FCS_var[i] = other.FCS_var[i];
}

void EthernetFrame::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->Preamble_var,7);
    doPacking(b,this->SFD_var,1);
    doPacking(b,this->MACaddr_var,6);
    doPacking(b,this->MACsrc_var,6);
    doPacking(b,this->FCS_var,4);
}

void EthernetFrame::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->Preamble_var,7);
    doUnpacking(b,this->SFD_var,1);
    doUnpacking(b,this->MACaddr_var,6);
    doUnpacking(b,this->MACsrc_var,6);
    doUnpacking(b,this->FCS_var,4);
}

unsigned int EthernetFrame::getPreambleArraySize() const
{
    return 7;
}

char EthernetFrame::getPreamble(unsigned int k) const
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    return Preamble_var[k];
}

void EthernetFrame::setPreamble(unsigned int k, char Preamble)
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    this->Preamble_var[k] = Preamble;
}

unsigned int EthernetFrame::getSFDArraySize() const
{
    return 1;
}

char EthernetFrame::getSFD(unsigned int k) const
{
    if (k>=1) throw cRuntimeError("Array of size 1 indexed by %lu", (unsigned long)k);
    return SFD_var[k];
}

void EthernetFrame::setSFD(unsigned int k, char SFD)
{
    if (k>=1) throw cRuntimeError("Array of size 1 indexed by %lu", (unsigned long)k);
    this->SFD_var[k] = SFD;
}

unsigned int EthernetFrame::getMACaddrArraySize() const
{
    return 6;
}

char EthernetFrame::getMACaddr(unsigned int k) const
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    return MACaddr_var[k];
}

void EthernetFrame::setMACaddr(unsigned int k, char MACaddr)
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    this->MACaddr_var[k] = MACaddr;
}

unsigned int EthernetFrame::getMACsrcArraySize() const
{
    return 6;
}

char EthernetFrame::getMACsrc(unsigned int k) const
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    return MACsrc_var[k];
}

void EthernetFrame::setMACsrc(unsigned int k, char MACsrc)
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    this->MACsrc_var[k] = MACsrc;
}

unsigned int EthernetFrame::getFCSArraySize() const
{
    return 4;
}

char EthernetFrame::getFCS(unsigned int k) const
{
    if (k>=4) throw cRuntimeError("Array of size 4 indexed by %lu", (unsigned long)k);
    return FCS_var[k];
}

void EthernetFrame::setFCS(unsigned int k, char FCS)
{
    if (k>=4) throw cRuntimeError("Array of size 4 indexed by %lu", (unsigned long)k);
    this->FCS_var[k] = FCS;
}

class EthernetFrameDescriptor : public cClassDescriptor
{
  public:
    EthernetFrameDescriptor();
    virtual ~EthernetFrameDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(EthernetFrameDescriptor);

EthernetFrameDescriptor::EthernetFrameDescriptor() : cClassDescriptor("EthernetFrame", "cPacket")
{
}

EthernetFrameDescriptor::~EthernetFrameDescriptor()
{
}

bool EthernetFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EthernetFrame *>(obj)!=NULL;
}

const char *EthernetFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EthernetFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int EthernetFrameDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *EthernetFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Preamble",
        "SFD",
        "MACaddr",
        "MACsrc",
        "FCS",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int EthernetFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='P' && strcmp(fieldName, "Preamble")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SFD")==0) return base+1;
    if (fieldName[0]=='M' && strcmp(fieldName, "MACaddr")==0) return base+2;
    if (fieldName[0]=='M' && strcmp(fieldName, "MACsrc")==0) return base+3;
    if (fieldName[0]=='F' && strcmp(fieldName, "FCS")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EthernetFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "char",
        "char",
        "char",
        "char",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *EthernetFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int EthernetFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EthernetFrame *pp = (EthernetFrame *)object; (void)pp;
    switch (field) {
        case 0: return 7;
        case 1: return 1;
        case 2: return 6;
        case 3: return 6;
        case 4: return 4;
        default: return 0;
    }
}

std::string EthernetFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EthernetFrame *pp = (EthernetFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPreamble(i));
        case 1: return long2string(pp->getSFD(i));
        case 2: return long2string(pp->getMACaddr(i));
        case 3: return long2string(pp->getMACsrc(i));
        case 4: return long2string(pp->getFCS(i));
        default: return "";
    }
}

bool EthernetFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EthernetFrame *pp = (EthernetFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setPreamble(i,string2long(value)); return true;
        case 1: pp->setSFD(i,string2long(value)); return true;
        case 2: pp->setMACaddr(i,string2long(value)); return true;
        case 3: pp->setMACsrc(i,string2long(value)); return true;
        case 4: pp->setFCS(i,string2long(value)); return true;
        default: return false;
    }
}

const char *EthernetFrameDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *EthernetFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EthernetFrame *pp = (EthernetFrame *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


