#ifndef BYTE_H
#define BYTE_H

class Byte
{
private:

	int data_, mask_;
public:

	Byte(int data, int mask);

	int get_data();
	int get_mask();

	Byte operator& (Byte byte);
	Byte operator| (Byte byte);
};

#endif