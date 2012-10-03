//
// Generated file, do not edit! Created by opp_msgc 4.2 from applicationlayer/EtherCatFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "EtherCatFrame_m.h"

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




type12PDU::type12PDU()
{
    prova = 0;
}

void doPacking(cCommBuffer *b, type12PDU& a)
{
    doPacking(b,a.prova);
}

void doUnpacking(cCommBuffer *b, type12PDU& a)
{
    doUnpacking(b,a.prova);
}

class type12PDUDescriptor : public cClassDescriptor
{
  public:
    type12PDUDescriptor();
    virtual ~type12PDUDescriptor();

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

Register_ClassDescriptor(type12PDUDescriptor);

type12PDUDescriptor::type12PDUDescriptor() : cClassDescriptor("type12PDU", "")
{
}

type12PDUDescriptor::~type12PDUDescriptor()
{
}

bool type12PDUDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<type12PDU *>(obj)!=NULL;
}

const char *type12PDUDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int type12PDUDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int type12PDUDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *type12PDUDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "prova",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int type12PDUDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prova")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *type12PDUDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *type12PDUDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int type12PDUDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    type12PDU *pp = (type12PDU *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string type12PDUDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    type12PDU *pp = (type12PDU *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->prova);
        default: return "";
    }
}

bool type12PDUDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    type12PDU *pp = (type12PDU *)object; (void)pp;
    switch (field) {
        case 0: pp->prova = string2long(value); return true;
        default: return false;
    }
}

const char *type12PDUDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *type12PDUDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    type12PDU *pp = (type12PDU *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(EtherCatFrame);

EtherCatFrame::EtherCatFrame(const char *name, int kind) : cPacket(name,kind)
{
    this->lenght_var = 0;
    this->reserved_var = 0;
    this->type_var = 0;
    this->data_var = 0;
}

EtherCatFrame::EtherCatFrame(const EtherCatFrame& other) : cPacket(other)
{
    copy(other);
}

EtherCatFrame::~EtherCatFrame()
{
}

EtherCatFrame& EtherCatFrame::operator=(const EtherCatFrame& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void EtherCatFrame::copy(const EtherCatFrame& other)
{
    this->lenght_var = other.lenght_var;
    this->reserved_var = other.reserved_var;
    this->type_var = other.type_var;
    for (unsigned int i=0; i<10; i++)
        this->pdu_var[i] = other.pdu_var[i];
    this->data_var = other.data_var;
}

void EtherCatFrame::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->lenght_var);
    doPacking(b,this->reserved_var);
    doPacking(b,this->type_var);
    doPacking(b,this->pdu_var,10);
    doPacking(b,this->data_var);
}

void EtherCatFrame::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->lenght_var);
    doUnpacking(b,this->reserved_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->pdu_var,10);
    doUnpacking(b,this->data_var);
}

int EtherCatFrame::getLenght() const
{
    return lenght_var;
}

void EtherCatFrame::setLenght(int lenght)
{
    this->lenght_var = lenght;
}

char EtherCatFrame::getReserved() const
{
    return reserved_var;
}

void EtherCatFrame::setReserved(char reserved)
{
    this->reserved_var = reserved;
}

char EtherCatFrame::getType() const
{
    return type_var;
}

void EtherCatFrame::setType(char type)
{
    this->type_var = type;
}

unsigned int EtherCatFrame::getPduArraySize() const
{
    return 10;
}

type12PDU& EtherCatFrame::getPdu(unsigned int k)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    return pdu_var[k];
}

void EtherCatFrame::setPdu(unsigned int k, const type12PDU& pdu)
{
    if (k>=10) throw cRuntimeError("Array of size 10 indexed by %lu", (unsigned long)k);
    this->pdu_var[k] = pdu;
}

int EtherCatFrame::getData() const
{
    return data_var;
}

void EtherCatFrame::setData(int data)
{
    this->data_var = data;
}

class EtherCatFrameDescriptor : public cClassDescriptor
{
  public:
    EtherCatFrameDescriptor();
    virtual ~EtherCatFrameDescriptor();

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

Register_ClassDescriptor(EtherCatFrameDescriptor);

EtherCatFrameDescriptor::EtherCatFrameDescriptor() : cClassDescriptor("EtherCatFrame", "cPacket")
{
}

EtherCatFrameDescriptor::~EtherCatFrameDescriptor()
{
}

bool EtherCatFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EtherCatFrame *>(obj)!=NULL;
}

const char *EtherCatFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EtherCatFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int EtherCatFrameDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *EtherCatFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "lenght",
        "reserved",
        "type",
        "pdu",
        "data",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int EtherCatFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lenght")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "pdu")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EtherCatFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "char",
        "char",
        "type12PDU",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *EtherCatFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int EtherCatFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EtherCatFrame *pp = (EtherCatFrame *)object; (void)pp;
    switch (field) {
        case 3: return 10;
        default: return 0;
    }
}

std::string EtherCatFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EtherCatFrame *pp = (EtherCatFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getLenght());
        case 1: return long2string(pp->getReserved());
        case 2: return long2string(pp->getType());
        case 3: {std::stringstream out; out << pp->getPdu(i); return out.str();}
        case 4: return long2string(pp->getData());
        default: return "";
    }
}

bool EtherCatFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EtherCatFrame *pp = (EtherCatFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setLenght(string2long(value)); return true;
        case 1: pp->setReserved(string2long(value)); return true;
        case 2: pp->setType(string2long(value)); return true;
        case 4: pp->setData(string2long(value)); return true;
        default: return false;
    }
}

const char *EtherCatFrameDescriptor::getFieldStructName(void *object, int field) const
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
        "type12PDU",
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *EtherCatFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EtherCatFrame *pp = (EtherCatFrame *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getPdu(i)); break;
        default: return NULL;
    }
}


