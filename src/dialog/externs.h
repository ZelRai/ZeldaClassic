#pragma once

#include "base/headers.h"
#include "base/containers.h"

void call_cpool_pages(optional<int> val = nullopt);
void call_autoc_pages(optional<int> val = nullopt);
void call_alias_pages(optional<int> val = nullopt);

optional<int32_t> call_get_num(string const& lbl, int32_t dv, int32_t max = 0, int32_t min = 0);
optional<int32_t> call_get_num(string const& lbl, string const& inf, int32_t dv, int32_t max = 0, int32_t min = 0);
optional<zfix> call_get_zfix(string const& lbl, zfix dv, zfix max = 0_zf, zfix min = 0_zf);
optional<zfix> call_get_zfix(string const& lbl, string const& inf, zfix dv, zfix max = 0_zf, zfix min = 0_zf);

void displayinfo(string const& title, string const& text, string subtext = "");
void displayinfo(string const& title, vector<string> const& lines, string subtext = "");

bool call_checklist_dialog(string const& title, vector<string> const& flagnames, bitstring& flags);
