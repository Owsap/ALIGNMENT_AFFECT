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
