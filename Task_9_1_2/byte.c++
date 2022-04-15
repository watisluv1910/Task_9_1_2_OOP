#include "byte.h"

Byte::Byte(int data, int mask)
{
	this->data_ = data;
	this->mask_ = mask;
}

int Byte::get_data()
{
	return this->data_;
}

int Byte::get_mask()
{
	return this->mask_;
}

Byte Byte::operator&(Byte byte)
{
	int local_mask = this->mask_ & byte.mask_;

	int data_with_local_mask = this->data_ & local_mask;

	int bite_data_with_local_mask = byte.data_ & local_mask;

	int xor_data_with_local_mask = 
		(data_with_local_mask & bite_data_with_local_mask) ^ data_with_local_mask;

	return Byte((this->data_ ^ xor_data_with_local_mask), this->mask_);
}

Byte Byte::operator|(Byte byte)
{
	int local_mask = this->mask_ & byte.mask_;

	int data_with_local_mask = this->data_ & local_mask;

	int bite_data_with_local_mask = byte.data_ & local_mask;

	int or_data_with_local_mask = data_with_local_mask | bite_data_with_local_mask;

	return Byte((this->data_ | or_data_with_local_mask), this->mask_);
}

