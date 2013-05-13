#ifndef DESCRIPTOR_H_GUARD
#define DESCRIPTOR_H_GUARD

#include "RegisterTable.h"
#include "MemoryTable.h"

class DescriptorTable
{
private:
	MemoryTable   mTable;	
	RegisterTable fTable;
	RegisterTable iTable;

public:

	// TODO
	// static void setFloatTableRange();
	// static void setIntegerTableRange();

	// TODO 
	RegisterInfo getFloatRegister(VarId vid);
	RegisterInfo getIntegerRegister(VarId vid);

	static DescriptorTable& getInstance()
	{
		static DescriptorTable instance;
		return instance;
	}

private:
	DescriptorTable();
	DescriptorTable(DescriptorTable const&);
	void operator=(DescriptorTable const&);
 };

#endif
