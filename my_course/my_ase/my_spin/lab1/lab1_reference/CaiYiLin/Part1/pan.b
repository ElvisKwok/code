	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* CLAIM fork_unique */
;
		;
		
	case 4: /* STATE 8 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC :init: */

	case 5: /* STATE 1 */
		;
	/* 0 */	((P2 *)this)->i = trpt->bup.oval;
		;
		;
		goto R999;

	case 6: /* STATE 4 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 7: /* STATE 5 */
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 8: /* STATE 6 */
		;
		((P2 *)this)->i = trpt->bup.oval;
		;
		goto R999;

	case 9: /* STATE 10 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC fork_proc */

	case 10: /* STATE 3 */
		;
		((P1 *)this)->next_serve = trpt->bup.ovals[1];
		((P1 *)this)->cur_serve = trpt->bup.ovals[0];
		;
		ungrab_ints(trpt->bup.ovals, 2);
		goto R999;

	case 11: /* STATE 6 */
		;
		((P1 *)this)->next_serve = trpt->bup.ovals[1];
		((P1 *)this)->cur_serve = trpt->bup.ovals[0];
		;
		ungrab_ints(trpt->bup.ovals, 2);
		goto R999;

	case 12: /* STATE 9 */
		;
		XX = 1;
		unrecv(now.fork_ch[ Index(((P1 *)this)->fork_id, 5) ], XX-1, 0, ((P1 *)this)->req, 1);
		((P1 *)this)->req = trpt->bup.oval;
		;
		;
		goto R999;
;
		;
		
	case 14: /* STATE 11 */
		;
		_m = unsend(now.phil_ch[ Index(((P1 *)this)->req, 5) ]);
		;
		goto R999;

	case 15: /* STATE 12 */
		;
	/* 0 */	((P1 *)this)->req = trpt->bup.ovals[1];
		XX = 1;
		unrecv(now.release_ch[ Index(((P1 *)this)->fork_id, 5) ], XX-1, 0, ((P1 *)this)->req, 1);
		((P1 *)this)->req = trpt->bup.ovals[0];
		;
		;
		ungrab_ints(trpt->bup.ovals, 2);
		goto R999;

	case 16: /* STATE 15 */
		;
		((P1 *)this)->next_serve = trpt->bup.ovals[2];
		((P1 *)this)->cur_serve = trpt->bup.ovals[1];
		((P1 *)this)->temp = trpt->bup.ovals[0];
		;
		ungrab_ints(trpt->bup.ovals, 3);
		goto R999;

	case 17: /* STATE 17 */
		;
		_m = unsend(now.phil_ch[ Index(((P1 *)this)->req, 5) ]);
		;
		goto R999;

	case 18: /* STATE 23 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC phil */
;
		;
		
	case 20: /* STATE 2 */
		;
		_m = unsend(now.fork_ch[ Index(((P0 *)this)->fork_left, 5) ]);
		;
		goto R999;

	case 21: /* STATE 3 */
		;
		XX = 1;
		unrecv(now.phil_ch[ Index(((P0 *)this)->id, 5) ], XX-1, 0, ((P0 *)this)->response, 1);
		((P0 *)this)->response = trpt->bup.oval;
		;
		;
		goto R999;

	case 22: /* STATE 4 */
		;
	/* 0 */	((P0 *)this)->response = trpt->bup.oval;
		;
		;
		goto R999;

	case 23: /* STATE 13 */
		;
		now.fork_used[ Index(((P0 *)this)->fork_left, 5) ] = trpt->bup.oval;
		;
		goto R999;

	case 24: /* STATE 14 */
		;
		_m = unsend(now.fork_ch[ Index(((P0 *)this)->fork_right, 5) ]);
		;
		goto R999;

	case 25: /* STATE 15 */
		;
		XX = 1;
		unrecv(now.phil_ch[ Index(((P0 *)this)->id, 5) ], XX-1, 0, ((P0 *)this)->response, 1);
		((P0 *)this)->response = trpt->bup.oval;
		;
		;
		goto R999;

	case 26: /* STATE 16 */
		;
	/* 0 */	((P0 *)this)->response = trpt->bup.oval;
		;
		;
		goto R999;

	case 27: /* STATE 25 */
		;
		now.fork_used[ Index(((P0 *)this)->fork_right, 5) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		;
		;
		
	case 31: /* STATE 29 */
		;
		now.fork_used[ Index(((P0 *)this)->fork_left, 5) ] = trpt->bup.oval;
		;
		goto R999;

	case 32: /* STATE 30 */
		;
		_m = unsend(now.release_ch[ Index(((P0 *)this)->fork_left, 5) ]);
		;
		goto R999;

	case 33: /* STATE 31 */
		;
		now.fork_used[ Index(((P0 *)this)->fork_right, 5) ] = trpt->bup.oval;
		;
		goto R999;

	case 34: /* STATE 32 */
		;
		_m = unsend(now.release_ch[ Index(((P0 *)this)->fork_right, 5) ]);
		;
		goto R999;

	case 35: /* STATE 36 */
		;
		p_restor(II);
		;
		;
		goto R999;
	}

