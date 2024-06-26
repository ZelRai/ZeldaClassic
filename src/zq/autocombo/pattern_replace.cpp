#include "zq/autocombo/autopattern_base.h"
#include "zq/autocombo/pattern_replace.h"
#include <base/zsys.h>

namespace AutoPattern
{
	bool replace::execute(int32_t exscreen, int32_t expos)
	{
		apcombo* ap = add(exscreen, expos, true);
		if (!ap)
			return false;
		int32_t newcid = convert_cid(ap->cid, false);
		if (newcid > 0)
		{
			ap->cid = newcid;
			ap->force_cset = true;
			ap->changed = true;
		}

		apply_changes();
		return true;
	}
	bool replace::erase(int32_t exscreen, int32_t expos)
	{
		apcombo* ap = add(exscreen, expos, true);
		if (!ap)
			return false;
		int32_t newcid = convert_cid(ap->cid, true);
		if (newcid > 0)
		{
			ap->cid = newcid;
			ap->force_cset = true;
			ap->changed = true;
		}

		apply_changes();
		return true;
	}
	int32_t replace::get_floating_cid(int32_t exscreen, int32_t expos)
	{
		apcombo* ap = add(exscreen, expos, true);
		if (!ap)
			return 0;
		int32_t newcid = convert_cid(ap->cid, false);
		if (newcid > 0)
			return newcid;
		return ap->cid;
	}

	uint32_t replace::slot_to_flags(int32_t slot)
	{
		return 0;
	}
	int32_t replace::flags_to_slot(uint32_t flags)
	{
		return 0;
	}

	int32_t replace::convert_cid(int32_t cid, bool revert)
	{
		for (int32_t q = revert ? 1 : 0; q < source->combos.size(); q += 2)
		{
			if (source->combos[q].cid == cid)
			{
				if (revert)
					return source->combos[q - 1].cid;
				else
					return source->combos[q + 1].cid;
			}
		}
		return -1;
	}
}