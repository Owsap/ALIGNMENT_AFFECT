/// 1.
// Search @ void CHARACTER::ClearAffect
			if (IS_NO_CLEAR_ON_DEATH_AFFECT(pkAff->dwType) || IS_NO_SAVE_AFFECT(pkAff->dwType))
			{
				++it;
				continue;
			}

// Add below
#if defined(__ALIGNMENT_AFFECT__)
			if (pkAff->dwType >= AFFECT_ALIGNMENT)
			{
				++it;
				continue;
			}
#endif



/// 2.
// Search
	if (afOld != m_afAffectFlag || lMovSpd != GetPoint(POINT_MOV_SPEED) || lAttSpd != GetPoint(POINT_ATT_SPEED))
// Add above
#if defined(__ALIGNMENT_AFFECT__)
	AlignmentBonus();
#endif
