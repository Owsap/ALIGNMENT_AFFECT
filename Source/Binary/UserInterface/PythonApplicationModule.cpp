/// 1.
// Add to the bottom of the document above }
#if defined(ENABLE_ALIGNMENT_AFFECT)
	PyModule_AddIntConstant(poModule, "ENABLE_ALIGNMENT_AFFECT", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_ALIGNMENT_AFFECT", 0);
#endif