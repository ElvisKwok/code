#define rand	pan_rand
#define pthread_equal(a,b)	((a)==(b))
#if defined(HAS_CODE) && defined(VERBOSE)
	#ifdef BFS_PAR
		bfs_printf("Pr: %d Tr: %d\n", II, t->forw);
	#else
		cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
	#endif
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* CLAIM l */
	case 3: // STATE 1 - _spin_nvr.tmp:4 - [(!(csq))] (0:0:0 - 1)
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported1 = 0;
			if (verbose && !reported1)
			{	int nn = (int) ((Pclaim *)pptr(0))->_n;
				printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported1 = 1;
				fflush(stdout);
		}	}
#else
		{	static int reported1 = 0;
			if (verbose && !reported1)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported1 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[2][1] = 1;
		if (!( !(((int)now.csq))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: // STATE 3 - _spin_nvr.tmp:5 - [(!(csp))] (0:0:0 - 1)
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported3 = 0;
			if (verbose && !reported3)
			{	int nn = (int) ((Pclaim *)pptr(0))->_n;
				printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported3 = 1;
				fflush(stdout);
		}	}
#else
		{	static int reported3 = 0;
			if (verbose && !reported3)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported3 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[2][3] = 1;
		if (!( !(((int)now.csp))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 5: // STATE 8 - _spin_nvr.tmp:10 - [(!(csq))] (0:0:0 - 1)
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported8 = 0;
			if (verbose && !reported8)
			{	int nn = (int) ((Pclaim *)pptr(0))->_n;
				printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported8 = 1;
				fflush(stdout);
		}	}
#else
		{	static int reported8 = 0;
			if (verbose && !reported8)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported8 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[2][8] = 1;
		if (!( !(((int)now.csq))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 6: // STATE 13 - _spin_nvr.tmp:15 - [(!(csp))] (0:0:0 - 1)
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported13 = 0;
			if (verbose && !reported13)
			{	int nn = (int) ((Pclaim *)pptr(0))->_n;
				printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported13 = 1;
				fflush(stdout);
		}	}
#else
		{	static int reported13 = 0;
			if (verbose && !reported13)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported13 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[2][13] = 1;
		if (!( !(((int)now.csp))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 7: // STATE 18 - _spin_nvr.tmp:17 - [-end-] (0:0:0 - 1)
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported18 = 0;
			if (verbose && !reported18)
			{	int nn = (int) ((Pclaim *)pptr(0))->_n;
				printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported18 = 1;
				fflush(stdout);
		}	}
#else
		{	static int reported18 = 0;
			if (verbose && !reported18)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported18 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[2][18] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC Q */
	case 8: // STATE 1 - liveness1.pml:22 - [(!(inCriticalP))] (4:0:1 - 1)
		IfNotBlocked
		reached[1][1] = 1;
		if (!( !(((int)now.inCriticalP))))
			continue;
		/* merge: inCriticalQ = 1(0, 2, 4) */
		reached[1][2] = 1;
		(trpt+1)->bup.oval = ((int)now.inCriticalQ);
		now.inCriticalQ = 1;
#ifdef VAR_RANGES
		logval("inCriticalQ", ((int)now.inCriticalQ));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 9: // STATE 4 - liveness1.pml:25 - [csq = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[1][4] = 1;
		(trpt+1)->bup.oval = ((int)now.csq);
		now.csq = 1;
#ifdef VAR_RANGES
		logval("csq", ((int)now.csq));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 10: // STATE 5 - liveness1.pml:27 - [csq = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[1][5] = 1;
		(trpt+1)->bup.oval = ((int)now.csq);
		now.csq = 0;
#ifdef VAR_RANGES
		logval("csq", ((int)now.csq));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 11: // STATE 6 - liveness1.pml:28 - [inCriticalQ = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[1][6] = 1;
		(trpt+1)->bup.oval = ((int)now.inCriticalQ);
		now.inCriticalQ = 0;
#ifdef VAR_RANGES
		logval("inCriticalQ", ((int)now.inCriticalQ));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 12: // STATE 10 - liveness1.pml:30 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[1][10] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC P */
	case 13: // STATE 1 - liveness1.pml:9 - [(!(inCriticalQ))] (4:0:1 - 1)
		IfNotBlocked
		reached[0][1] = 1;
		if (!( !(((int)now.inCriticalQ))))
			continue;
		/* merge: inCriticalP = 1(0, 2, 4) */
		reached[0][2] = 1;
		(trpt+1)->bup.oval = ((int)now.inCriticalP);
		now.inCriticalP = 1;
#ifdef VAR_RANGES
		logval("inCriticalP", ((int)now.inCriticalP));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 14: // STATE 4 - liveness1.pml:12 - [csp = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[0][4] = 1;
		(trpt+1)->bup.oval = ((int)now.csp);
		now.csp = 1;
#ifdef VAR_RANGES
		logval("csp", ((int)now.csp));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 15: // STATE 5 - liveness1.pml:14 - [csp = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[0][5] = 1;
		(trpt+1)->bup.oval = ((int)now.csp);
		now.csp = 0;
#ifdef VAR_RANGES
		logval("csp", ((int)now.csp));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 16: // STATE 6 - liveness1.pml:15 - [inCriticalP = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[0][6] = 1;
		(trpt+1)->bup.oval = ((int)now.inCriticalP);
		now.inCriticalP = 0;
#ifdef VAR_RANGES
		logval("inCriticalP", ((int)now.inCriticalP));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 17: // STATE 10 - liveness1.pml:17 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[0][10] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

