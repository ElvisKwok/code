	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* CLAIM l */
;
		;
		;
		;
		;
		;
		;
		;
		
	case 7: // STATE 18
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC Q */

	case 8: // STATE 2
		;
		now.inCriticalQ = trpt->bup.oval;
		;
		goto R999;

	case 9: // STATE 4
		;
		now.csq = trpt->bup.oval;
		;
		goto R999;

	case 10: // STATE 5
		;
		now.csq = trpt->bup.oval;
		;
		goto R999;

	case 11: // STATE 6
		;
		now.inCriticalQ = trpt->bup.oval;
		;
		goto R999;

	case 12: // STATE 10
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC P */

	case 13: // STATE 2
		;
		now.inCriticalP = trpt->bup.oval;
		;
		goto R999;

	case 14: // STATE 4
		;
		now.csp = trpt->bup.oval;
		;
		goto R999;

	case 15: // STATE 5
		;
		now.csp = trpt->bup.oval;
		;
		goto R999;

	case 16: // STATE 6
		;
		now.inCriticalP = trpt->bup.oval;
		;
		goto R999;

	case 17: // STATE 10
		;
		p_restor(II);
		;
		;
		goto R999;
	}

