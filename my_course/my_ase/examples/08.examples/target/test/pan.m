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

		 /* CLAIM m */
	case 3: // STATE 1 - _spin_nvr.tmp:4 - [(!(!(((P._p==cs)&&(Q._p==cs)))))] (4:0:0 - 1)
		
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
		if (!( !( !(((((int)((P0 *)Pptr(f_pid(0)))->_p)==4)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==4))))))
			continue;
		/* merge: assert(!(!(!(((P._p==cs)&&(Q._p==cs))))))(0, 2, 4) */
		reached[2][2] = 1;
		spin_assert( !( !( !(((((int)((P0 *)Pptr(f_pid(0)))->_p)==4)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==4))))), " !( !( !(((P._p==cs)&&(Q._p==cs)))))", II, tt, t);
		/* merge: .(goto)(0, 5, 4) */
		reached[2][5] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 4: // STATE 8 - _spin_nvr.tmp:8 - [-end-] (0:0:0 - 1)
		
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
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC Q */
	case 5: // STATE 1 - noGhost.pml:18 - [(!(inCriticalP))] (4:0:1 - 1)
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
	case 6: // STATE 4 - noGhost.pml:22 - [inCriticalQ = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[1][4] = 1;
		(trpt+1)->bup.oval = ((int)now.inCriticalQ);
		now.inCriticalQ = 0;
#ifdef VAR_RANGES
		logval("inCriticalQ", ((int)now.inCriticalQ));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 7: // STATE 8 - noGhost.pml:24 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[1][8] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC P */
	case 8: // STATE 1 - noGhost.pml:7 - [(!(inCriticalQ))] (4:0:1 - 1)
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
	case 9: // STATE 4 - noGhost.pml:11 - [inCriticalP = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[0][4] = 1;
		(trpt+1)->bup.oval = ((int)now.inCriticalP);
		now.inCriticalP = 0;
#ifdef VAR_RANGES
		logval("inCriticalP", ((int)now.inCriticalP));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 10: // STATE 8 - noGhost.pml:13 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[0][8] = 1;
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

