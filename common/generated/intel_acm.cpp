// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "intel_acm.h"
#include "../kaitai/exceptions.h"
const std::set<intel_acm_t::known_header_version_t> intel_acm_t::_values_known_header_version_t{
    intel_acm_t::KNOWN_HEADER_VERSION_V0_0,
    intel_acm_t::KNOWN_HEADER_VERSION_V3_0,
    intel_acm_t::KNOWN_HEADER_VERSION_V5_4,
};
bool intel_acm_t::_is_defined_known_header_version_t(intel_acm_t::known_header_version_t v) {
    return intel_acm_t::_values_known_header_version_t.find(v) != intel_acm_t::_values_known_header_version_t.end();
}
const std::set<intel_acm_t::module_subtype_t> intel_acm_t::_values_module_subtype_t{
    intel_acm_t::MODULE_SUBTYPE_TXT,
    intel_acm_t::MODULE_SUBTYPE_STARTUP,
    intel_acm_t::MODULE_SUBTYPE_BOOT_GUARD,
};
bool intel_acm_t::_is_defined_module_subtype_t(intel_acm_t::module_subtype_t v) {
    return intel_acm_t::_values_module_subtype_t.find(v) != intel_acm_t::_values_module_subtype_t.end();
}

intel_acm_t::intel_acm_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, intel_acm_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root ? p__root : this;
    m_header = nullptr;
    _read();
}

void intel_acm_t::_read() {
    m_header = std::unique_ptr<header_t>(new header_t(m__io, this, m__root));
    m_body = m__io->read_bytes(4 * ((header()->module_size() - header()->header_size()) - header()->scratch_space_size()));
}

intel_acm_t::~intel_acm_t() {
    _clean_up();
}

void intel_acm_t::_clean_up() {
}

intel_acm_t::header_t::header_t(kaitai::kstream* p__io, intel_acm_t* p__parent, intel_acm_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void intel_acm_t::header_t::_read() {
    m_module_type = m__io->read_u2le();
    if (!(m_module_type == 2)) {
        throw kaitai::validation_not_equal_error<uint16_t>(2, m_module_type, m__io, std::string("/types/header/seq/0"));
    }
    m_module_subtype = static_cast<intel_acm_t::module_subtype_t>(m__io->read_u2le());
    m_header_size = m__io->read_u4le();
    m_header_version = m__io->read_u4le();
    m_chipset_id = m__io->read_u2le();
    m_flags = m__io->read_u2le();
    m_module_vendor = m__io->read_u4le();
    if (!(m_module_vendor == 32902)) {
        throw kaitai::validation_not_equal_error<uint32_t>(32902, m_module_vendor, m__io, std::string("/types/header/seq/6"));
    }
    m_date_day = m__io->read_u1();
    m_date_month = m__io->read_u1();
    m_date_year = m__io->read_u2le();
    m_module_size = m__io->read_u4le();
    m_acm_svn = m__io->read_u2le();
    m_se_svn = m__io->read_u2le();
    m_code_control_flags = m__io->read_u4le();
    m_error_entry_point = m__io->read_u4le();
    m_gdt_max = m__io->read_u4le();
    m_gdt_base = m__io->read_u4le();
    m_segment_sel = m__io->read_u4le();
    m_entry_point = m__io->read_u4le();
    m_reserved = m__io->read_bytes(64);
    m_key_size = m__io->read_u4le();
    m_scratch_space_size = m__io->read_u4le();
    m_rsa_public_key = m__io->read_bytes(4 * key_size());
    n_rsa_exponent = true;
    if (header_version() == 0) {
        n_rsa_exponent = false;
        m_rsa_exponent = m__io->read_u4le();
    }
    m_rsa_signature = m__io->read_bytes(4 * key_size());
    m_scratch_space = m__io->read_bytes(4 * scratch_space_size());
}

intel_acm_t::header_t::~header_t() {
    _clean_up();
}

void intel_acm_t::header_t::_clean_up() {
    if (!n_rsa_exponent) {
    }
}
