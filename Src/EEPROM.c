void EEPROM_write(uint32_t data, uint32_t address_block, uint8_t address_offset)//, uint32_t address)
{
	EEPROM_EEBLOCK_R = address_block;
	EEPROM_EEOFFSET_R = address_offset;
	
EEPROM_EERDWRINC_R = data;
}