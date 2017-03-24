// Types inherent to the CFB file format
// All of these should be outlined in doc/MSDN_CFB_Format_Spec.pdf
// Or at https://msdn.microsoft.com/en-us/library/dd942138.aspx

#ifndef CFB_TYPES_H
#define CFB_TYPES_H

// Sector ID Constants
const uint32_t MAXREGSECT   = 0xFFFFFFFA;
const uint32_t DIFSECT      = 0xFFFFFFFC;
const uint32_t FATSECT      = 0xFFFFFFFD;
const uint32_t ENDOFCHAIN   = 0xFFFFFFFE;
const uint32_t FREESECT     = 0xFFFFFFFF;

// Directory Entry Color Flags
const uint8_t CF_RED        = 0x00;
const uint8_t CF_BLACK      = 0x01;

// Directory Entry IDs
const uint32_t MAXREGSID    = 0xFFFFFFFA;
const uint32_t NOSTREAM     = 0xFFFFFFFF;

// Directory Entry Object Types
const uint8_t OT_UNKNOWN    = 0x00;
const uint8_t OT_STORAGE    = 0x01;
const uint8_t OT_STREAM     = 0x02;
const uint8_t OT_ROOT       = 0x05;

// Header is 512 bytes
// Contains map of structure for the rest of the file
// Since the Altium libraries are small, there's not a lot to worry about
typedef struct header_t
{
    uint8_t magic[8];
    uint8_t uid[16];
    uint8_t revision_number[2];
    uint8_t version_number[2];
    uint16_t byte_order;
    uint16_t sec_size;
    uint16_t short_sec_size;
    uint8_t spare1[10];
    uint32_t sec_count;
    uint32_t first_sec_id;
    uint32_t spare2;
    uint32_t min_std_stream_size;
    uint32_t first_short_sec_id;
    uint32_t short_sec_count;
    uint32_t first_master_sec_id;
    uint32_t master_sec_count;
    uint32_t master_sec_ids[109];
};

// Each Directory Entry is 128 bytes
// The directory entries comprise a red-black tree
typedef struct directory_entry_t
{
    char16_t entry_name[32];
    uint16_t size_of_name_buffer;
    uint8_t entry_type;
    uint8_t node_color;
    uint32_t dir_id_left;
    uint32_t dir_id_right;
    uint32_t dir_id_root;
    uint8_t uid[16];
    uint8_t flags[4];
    uint64_t created_time;
    uint64_t modified_time;
    uint32_t first_sec_id;
    uint32_t total_stream_size;
    uint32_t spare1;
};

#endif // CSB_TYPES_H