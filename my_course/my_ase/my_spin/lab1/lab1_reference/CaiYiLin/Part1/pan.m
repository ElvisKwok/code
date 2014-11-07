#define rand	pan_rand
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

		 /* CLAIM fork_unique */
	case 3: /* STATE 1 - _spin_nvr.tmp:3 - [(!((((((fork_used[0]<2)&&(fork_used[1]<2))&&(fork_used[2]<2))&&(fork_used[3]<2))&&(fork_used[4]<2))))] (0:0:0 - 1) */
		
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
		reached[3][1] = 1;
		if (!( !((((((now.fork_used[0]<2)&&(now.fork_used[1]<2))&&(now.fork_used[2]<2))&&(now.fork_used[3]<2))&&(now.fork_used[4]<2)))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 8 - _spin_nvr.tmp:8 - [-end-] (0:0:0 - 1) */
		
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
		reached[3][8] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC :init: */
	case 5: /* STATE 1 - Dining.pml:80 - [((i>=5))] (0:0:1 - 1) */
		IfNotBlocked
		reached[2][1] = 1;
		if (!((((P2 *)this)->i>=5)))
			continue;
		/* dead 1: i */  (trpt+1)->bup.oval = ((P2 *)this)->i;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P2 *)this)->i = 0;
		_m = 3; goto P999; /* 0 */
	case 6: /* STATE 4 - Dining.pml:81 - [(run phil(i))] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][4] = 1;
		if (!(addproc(II, 0, ((P2 *)this)->i)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 7: /* STATE 5 - Dining.pml:82 - [(run fork_proc(i))] (0:0:0 - 1) */
		IfNotBlocked
		reached[2][5] = 1;
		if (!(addproc(II, 1, ((P2 *)this)->i)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 8: /* STATE 6 - Dining.pml:83 - [i = (i+1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[2][6] = 1;
		(trpt+1)->bup.oval = ((P2 *)this)->i;
		((P2 *)this)->i = (((P2 *)this)->i+1);
#ifdef VAR_RANGES
		logval(":init::i", ((P2 *)this)->i);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 10 - Dining.pml:85 - [-end-] (0:0:0 - 3) */
		IfNotBlocked
		reached[2][10] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC fork_proc */
	case 10: /* STATE 1 - Dining.pml:55 - [(((fork_id%2)==0))] (20:0:2 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		if (!(((((P1 *)this)->fork_id%2)==0)))
			continue;
		/* merge: cur_serve = fork_id(20, 2, 20) */
		reached[1][2] = 1;
		(trpt+1)->bup.ovals = grab_ints(2);
		(trpt+1)->bup.ovals[0] = ((P1 *)this)->cur_serve;
		((P1 *)this)->cur_serve = ((P1 *)this)->fork_id;
#ifdef VAR_RANGES
		logval("fork_proc:cur_serve", ((P1 *)this)->cur_serve);
#endif
		;
		/* merge: next_serve = ((fork_id+1)%5)(20, 3, 20) */
		reached[1][3] = 1;
		(trpt+1)->bup.ovals[1] = ((P1 *)this)->next_serve;
		((P1 *)this)->next_serve = ((((P1 *)this)->fork_id+1)%5);
#ifdef VAR_RANGES
		logval("fork_proc:next_serve", ((P1 *)this)->next_serve);
#endif
		;
		/* merge: .(goto)(0, 8, 20) */
		reached[1][8] = 1;
		;
		/* merge: .(goto)(0, 21, 20) */
		reached[1][21] = 1;
		;
		_m = 3; goto P999; /* 4 */
	case 11: /* STATE 5 - Dining.pml:59 - [cur_serve = ((fork_id+1)%5)] (0:20:2 - 1) */
		IfNotBlocked
		reached[1][5] = 1;
		(trpt+1)->bup.ovals = grab_ints(2);
		(trpt+1)->bup.ovals[0] = ((P1 *)this)->cur_serve;
		((P1 *)this)->cur_serve = ((((P1 *)this)->fork_id+1)%5);
#ifdef VAR_RANGES
		logval("fork_proc:cur_serve", ((P1 *)this)->cur_serve);
#endif
		;
		/* merge: next_serve = fork_id(20, 6, 20) */
		reached[1][6] = 1;
		(trpt+1)->bup.ovals[1] = ((P1 *)this)->next_serve;
		((P1 *)this)->next_serve = ((P1 *)this)->fork_id;
#ifdef VAR_RANGES
		logval("fork_proc:next_serve", ((P1 *)this)->next_serve);
#endif
		;
		/* merge: .(goto)(0, 8, 20) */
		reached[1][8] = 1;
		;
		/* merge: .(goto)(0, 21, 20) */
		reached[1][21] = 1;
		;
		_m = 3; goto P999; /* 3 */
	case 12: /* STATE 9 - Dining.pml:64 - [fork_ch[fork_id]?req] (0:0:1 - 1) */
		reached[1][9] = 1;
		if (boq != now.fork_ch[ Index(((P1 *)this)->fork_id, 5) ]) continue;
		if (q_len(now.fork_ch[ Index(((P1 *)this)->fork_id, 5) ]) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P1 *)this)->req;
		;
		((P1 *)this)->req = qrecv(now.fork_ch[ Index(((P1 *)this)->fork_id, 5) ], XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("fork_proc:req", ((P1 *)this)->req);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", now.fork_ch[ Index(((P1 *)this)->fork_id, 5) ]);
		sprintf(simtmp, "%d", ((P1 *)this)->req); strcat(simvals, simtmp);		}
#endif
		if (q_zero(now.fork_ch[ Index(((P1 *)this)->fork_id, 5) ]))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		_m = 4; goto P999; /* 0 */
	case 13: /* STATE 10 - Dining.pml:66 - [((req==cur_serve))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][10] = 1;
		if (!((((P1 *)this)->req==((P1 *)this)->cur_serve)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 14: /* STATE 11 - Dining.pml:66 - [phil_ch[req]!1] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][11] = 1;
		if (q_len(now.phil_ch[ Index(((P1 *)this)->req, 5) ]))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[64];
			sprintf(simvals, "%d!", now.phil_ch[ Index(((P1 *)this)->req, 5) ]);
		sprintf(simtmp, "%d", 1); strcat(simvals, simtmp);		}
#endif
		
		qsend(now.phil_ch[ Index(((P1 *)this)->req, 5) ], 0, 1, 1);
		{ boq = now.phil_ch[ Index(((P1 *)this)->req, 5) ]; };
		_m = 2; goto P999; /* 0 */
	case 15: /* STATE 12 - Dining.pml:67 - [release_ch[fork_id]?req] (0:0:2 - 1) */
		reached[1][12] = 1;
		if (boq != now.release_ch[ Index(((P1 *)this)->fork_id, 5) ]) continue;
		if (q_len(now.release_ch[ Index(((P1 *)this)->fork_id, 5) ]) == 0) continue;

		XX=1;
		(trpt+1)->bup.ovals = grab_ints(2);
		(trpt+1)->bup.ovals[0] = ((P1 *)this)->req;
		;
		((P1 *)this)->req = qrecv(now.release_ch[ Index(((P1 *)this)->fork_id, 5) ], XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("fork_proc:req", ((P1 *)this)->req);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", now.release_ch[ Index(((P1 *)this)->fork_id, 5) ]);
		sprintf(simtmp, "%d", ((P1 *)this)->req); strcat(simvals, simtmp);		}
#endif
		if (q_zero(now.release_ch[ Index(((P1 *)this)->fork_id, 5) ]))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		/* dead 2: req */  (trpt+1)->bup.ovals[1] = ((P1 *)this)->req;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P1 *)this)->req = 0;
		_m = 4; goto P999; /* 0 */
	case 16: /* STATE 13 - Dining.pml:68 - [temp = cur_serve] (0:20:3 - 1) */
		IfNotBlocked
		reached[1][13] = 1;
		(trpt+1)->bup.ovals = grab_ints(3);
		(trpt+1)->bup.ovals[0] = ((P1 *)this)->temp;
		((P1 *)this)->temp = ((P1 *)this)->cur_serve;
#ifdef VAR_RANGES
		logval("fork_proc:temp", ((P1 *)this)->temp);
#endif
		;
		/* merge: cur_serve = next_serve(20, 14, 20) */
		reached[1][14] = 1;
		(trpt+1)->bup.ovals[1] = ((P1 *)this)->cur_serve;
		((P1 *)this)->cur_serve = ((P1 *)this)->next_serve;
#ifdef VAR_RANGES
		logval("fork_proc:cur_serve", ((P1 *)this)->cur_serve);
#endif
		;
		/* merge: next_serve = temp(20, 15, 20) */
		reached[1][15] = 1;
		(trpt+1)->bup.ovals[2] = ((P1 *)this)->next_serve;
		((P1 *)this)->next_serve = ((P1 *)this)->temp;
#ifdef VAR_RANGES
		logval("fork_proc:next_serve", ((P1 *)this)->next_serve);
#endif
		;
		/* merge: .(goto)(0, 19, 20) */
		reached[1][19] = 1;
		;
		/* merge: .(goto)(0, 21, 20) */
		reached[1][21] = 1;
		;
		_m = 3; goto P999; /* 4 */
	case 17: /* STATE 17 - Dining.pml:72 - [phil_ch[req]!-(1)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][17] = 1;
		if (q_len(now.phil_ch[ Index(((P1 *)this)->req, 5) ]))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[64];
			sprintf(simvals, "%d!", now.phil_ch[ Index(((P1 *)this)->req, 5) ]);
		sprintf(simtmp, "%d",  -(1)); strcat(simvals, simtmp);		}
#endif
		
		qsend(now.phil_ch[ Index(((P1 *)this)->req, 5) ], 0,  -(1), 1);
		{ boq = now.phil_ch[ Index(((P1 *)this)->req, 5) ]; };
		_m = 2; goto P999; /* 0 */
	case 18: /* STATE 23 - Dining.pml:75 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][23] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC phil */
	case 19: /* STATE 1 - Dining.pml:16 - [printf('Philosopher %d thinking\\n',id)] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][1] = 1;
		Printf("Philosopher %d thinking\n", ((P0 *)this)->id);
		_m = 3; goto P999; /* 0 */
	case 20: /* STATE 2 - Dining.pml:18 - [fork_ch[fork_left]!id] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][2] = 1;
		if (q_len(now.fork_ch[ Index(((P0 *)this)->fork_left, 5) ]))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[64];
			sprintf(simvals, "%d!", now.fork_ch[ Index(((P0 *)this)->fork_left, 5) ]);
		sprintf(simtmp, "%d", ((P0 *)this)->id); strcat(simvals, simtmp);		}
#endif
		
		qsend(now.fork_ch[ Index(((P0 *)this)->fork_left, 5) ], 0, ((P0 *)this)->id, 1);
		{ boq = now.fork_ch[ Index(((P0 *)this)->fork_left, 5) ]; };
		_m = 2; goto P999; /* 0 */
	case 21: /* STATE 3 - Dining.pml:19 - [phil_ch[id]?response] (0:0:1 - 1) */
		reached[0][3] = 1;
		if (boq != now.phil_ch[ Index(((P0 *)this)->id, 5) ]) continue;
		if (q_len(now.phil_ch[ Index(((P0 *)this)->id, 5) ]) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P0 *)this)->response;
		;
		((P0 *)this)->response = qrecv(now.phil_ch[ Index(((P0 *)this)->id, 5) ], XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("phil:response", ((P0 *)this)->response);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", now.phil_ch[ Index(((P0 *)this)->id, 5) ]);
		sprintf(simtmp, "%d", ((P0 *)this)->response); strcat(simvals, simtmp);		}
#endif
		if (q_zero(now.phil_ch[ Index(((P0 *)this)->id, 5) ]))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		_m = 4; goto P999; /* 0 */
	case 22: /* STATE 4 - Dining.pml:21 - [((response==1))] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][4] = 1;
		if (!((((P0 *)this)->response==1)))
			continue;
		/* dead 1: response */  (trpt+1)->bup.oval = ((P0 *)this)->response;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P0 *)this)->response = 0;
		_m = 3; goto P999; /* 0 */
	case 23: /* STATE 13 - Dining.pml:25 - [fork_used[fork_left] = (fork_used[fork_left]+1)] (0:0:1 - 3) */
		IfNotBlocked
		reached[0][13] = 1;
		(trpt+1)->bup.oval = now.fork_used[ Index(((P0 *)this)->fork_left, 5) ];
		now.fork_used[ Index(((P0 *)this)->fork_left, 5) ] = (now.fork_used[ Index(((P0 *)this)->fork_left, 5) ]+1);
#ifdef VAR_RANGES
		logval("fork_used[phil:fork_left]", now.fork_used[ Index(((P0 *)this)->fork_left, 5) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 24: /* STATE 14 - Dining.pml:28 - [fork_ch[fork_right]!id] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][14] = 1;
		if (q_len(now.fork_ch[ Index(((P0 *)this)->fork_right, 5) ]))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[64];
			sprintf(simvals, "%d!", now.fork_ch[ Index(((P0 *)this)->fork_right, 5) ]);
		sprintf(simtmp, "%d", ((P0 *)this)->id); strcat(simvals, simtmp);		}
#endif
		
		qsend(now.fork_ch[ Index(((P0 *)this)->fork_right, 5) ], 0, ((P0 *)this)->id, 1);
		{ boq = now.fork_ch[ Index(((P0 *)this)->fork_right, 5) ]; };
		_m = 2; goto P999; /* 0 */
	case 25: /* STATE 15 - Dining.pml:29 - [phil_ch[id]?response] (0:0:1 - 1) */
		reached[0][15] = 1;
		if (boq != now.phil_ch[ Index(((P0 *)this)->id, 5) ]) continue;
		if (q_len(now.phil_ch[ Index(((P0 *)this)->id, 5) ]) == 0) continue;

		XX=1;
		(trpt+1)->bup.oval = ((P0 *)this)->response;
		;
		((P0 *)this)->response = qrecv(now.phil_ch[ Index(((P0 *)this)->id, 5) ], XX-1, 0, 1);
#ifdef VAR_RANGES
		logval("phil:response", ((P0 *)this)->response);
#endif
		;
		
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[32];
			sprintf(simvals, "%d?", now.phil_ch[ Index(((P0 *)this)->id, 5) ]);
		sprintf(simtmp, "%d", ((P0 *)this)->response); strcat(simvals, simtmp);		}
#endif
		if (q_zero(now.phil_ch[ Index(((P0 *)this)->id, 5) ]))
		{	boq = -1;
#ifndef NOFAIR
			if (fairness
			&& !(trpt->o_pm&32)
			&& (now._a_t&2)
			&&  now._cnt[now._a_t&1] == II+2)
			{	now._cnt[now._a_t&1] -= 1;
#ifdef VERI
				if (II == 1)
					now._cnt[now._a_t&1] = 1;
#endif
#ifdef DEBUG
			printf("%3d: proc %d fairness ", depth, II);
			printf("Rule 2: --cnt to %d (%d)\n",
				now._cnt[now._a_t&1], now._a_t);
#endif
				trpt->o_pm |= (32|64);
			}
#endif

		};
		_m = 4; goto P999; /* 0 */
	case 26: /* STATE 16 - Dining.pml:31 - [((response==1))] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][16] = 1;
		if (!((((P0 *)this)->response==1)))
			continue;
		/* dead 1: response */  (trpt+1)->bup.oval = ((P0 *)this)->response;
#ifdef HAS_CODE
		if (!readtrail)
#endif
			((P0 *)this)->response = 0;
		_m = 3; goto P999; /* 0 */
	case 27: /* STATE 25 - Dining.pml:35 - [fork_used[fork_right] = (fork_used[fork_right]+1)] (0:0:1 - 3) */
		IfNotBlocked
		reached[0][25] = 1;
		(trpt+1)->bup.oval = now.fork_used[ Index(((P0 *)this)->fork_right, 5) ];
		now.fork_used[ Index(((P0 *)this)->fork_right, 5) ] = (now.fork_used[ Index(((P0 *)this)->fork_right, 5) ]+1);
#ifdef VAR_RANGES
		logval("fork_used[phil:fork_right]", now.fork_used[ Index(((P0 *)this)->fork_right, 5) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 28: /* STATE 26 - Dining.pml:37 - [assert((fork_used[fork_left]<2))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][26] = 1;
		spin_assert((now.fork_used[ Index(((P0 *)this)->fork_left, 5) ]<2), "(fork_used[fork_left]<2)", II, tt, t);
		_m = 3; goto P999; /* 0 */
	case 29: /* STATE 27 - Dining.pml:38 - [assert((fork_used[fork_right]<2))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][27] = 1;
		spin_assert((now.fork_used[ Index(((P0 *)this)->fork_right, 5) ]<2), "(fork_used[fork_right]<2)", II, tt, t);
		_m = 3; goto P999; /* 0 */
	case 30: /* STATE 28 - Dining.pml:40 - [printf('Philosopher %d is eating with fork %d and %d\\n',id,fork_left,fork_right)] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][28] = 1;
		Printf("Philosopher %d is eating with fork %d and %d\n", ((P0 *)this)->id, ((P0 *)this)->fork_left, ((P0 *)this)->fork_right);
		_m = 3; goto P999; /* 0 */
	case 31: /* STATE 29 - Dining.pml:42 - [fork_used[fork_left] = (fork_used[fork_left]-1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][29] = 1;
		(trpt+1)->bup.oval = now.fork_used[ Index(((P0 *)this)->fork_left, 5) ];
		now.fork_used[ Index(((P0 *)this)->fork_left, 5) ] = (now.fork_used[ Index(((P0 *)this)->fork_left, 5) ]-1);
#ifdef VAR_RANGES
		logval("fork_used[phil:fork_left]", now.fork_used[ Index(((P0 *)this)->fork_left, 5) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 32: /* STATE 30 - Dining.pml:43 - [release_ch[fork_left]!1] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][30] = 1;
		if (q_len(now.release_ch[ Index(((P0 *)this)->fork_left, 5) ]))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[64];
			sprintf(simvals, "%d!", now.release_ch[ Index(((P0 *)this)->fork_left, 5) ]);
		sprintf(simtmp, "%d", 1); strcat(simvals, simtmp);		}
#endif
		
		qsend(now.release_ch[ Index(((P0 *)this)->fork_left, 5) ], 0, 1, 1);
		{ boq = now.release_ch[ Index(((P0 *)this)->fork_left, 5) ]; };
		_m = 2; goto P999; /* 0 */
	case 33: /* STATE 31 - Dining.pml:45 - [fork_used[fork_right] = (fork_used[fork_right]-1)] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][31] = 1;
		(trpt+1)->bup.oval = now.fork_used[ Index(((P0 *)this)->fork_right, 5) ];
		now.fork_used[ Index(((P0 *)this)->fork_right, 5) ] = (now.fork_used[ Index(((P0 *)this)->fork_right, 5) ]-1);
#ifdef VAR_RANGES
		logval("fork_used[phil:fork_right]", now.fork_used[ Index(((P0 *)this)->fork_right, 5) ]);
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 34: /* STATE 32 - Dining.pml:46 - [release_ch[fork_right]!1] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][32] = 1;
		if (q_len(now.release_ch[ Index(((P0 *)this)->fork_right, 5) ]))
			continue;
#ifdef HAS_CODE
		if (readtrail && gui) {
			char simtmp[64];
			sprintf(simvals, "%d!", now.release_ch[ Index(((P0 *)this)->fork_right, 5) ]);
		sprintf(simtmp, "%d", 1); strcat(simvals, simtmp);		}
#endif
		
		qsend(now.release_ch[ Index(((P0 *)this)->fork_right, 5) ], 0, 1, 1);
		{ boq = now.release_ch[ Index(((P0 *)this)->fork_right, 5) ]; };
		_m = 2; goto P999; /* 0 */
	case 35: /* STATE 36 - Dining.pml:48 - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][36] = 1;
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

