/// 1.
// Search @ void CHARACTER::ShowAlignment
	if (bShow)
	{
		if (m_iAlignment != m_iRealAlignment)
		{
			m_iAlignment = m_iRealAlignment;
			UpdatePacket();
		}
	}
	else
	{
		if (m_iAlignment != 0)
		{
			m_iAlignment = 0;
			UpdatePacket();
		}
	}

// Add below
#if defined(__ALIGNMENT_AFFECT__)
	AlignmentBonus();
#endif

/// 2.
// Search
void CHARACTER::UpdateAlignment(int iAmount)

// Add above
#if defined(__ALIGNMENT_AFFECT__)
void CHARACTER::AlignmentBonus()
{
	if (IsPC() && (!GetDesc() || !GetDesc()->GetCharacter()))
		return;

	int iRealAlignment = m_iRealAlignment / 10;

	int iAlignmentBonus[MAX_ALIGNMENT_LEVEL][3] = {
		{ ALIGNMENT_LEVEL1 /* 12000 */, POINT_MAX_HP, 2000 },
		{ ALIGNMENT_LEVEL2 /* 8000 */, POINT_MAX_HP, 1500 },
		{ ALIGNMENT_LEVEL3 /* 4000 */, POINT_MAX_HP, 1000 },
		{ ALIGNMENT_LEVEL4 /* 1000 */, POINT_MAX_HP, 500 },
	};

	for (int i = 0; i < MAX_ALIGNMENT_LEVEL; ++i)
	{
		if (iRealAlignment >= iAlignmentBonus[i][0])
		{
			AddAffect(AFFECT_ALIGNMENT, iAlignmentBonus[i][1], iAlignmentBonus[i][2], AFF_NONE, INFINITE_AFFECT_DURATION, 0, true, true);
			return;
		}
	}

	RemoveAffect(AFFECT_ALIGNMENT);
}
#endif

/// 3.
// Search @ void CHARACTER::UpdateAlignment
	if (bShow)
	{
		m_iAlignment = m_iRealAlignment;

		if (i != m_iAlignment / 10)
			UpdatePacket();
	}

// Add below
#if defined(__ALIGNMENT_AFFECT__)
	AlignmentBonus();
#endif