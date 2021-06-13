uint32_t EEPROM_read(uint32_t address_block, uint8_t address_offset)//uint32_t address)
{
	EEPROM_EEBLOCK_R = address_block;
	EEPROM_EEOFFSET_R = address_offset;
return EEPROM_EERDWRINC_R;
}