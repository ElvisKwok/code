	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* CLAIM m */
;
		
	case 3: // STATE 1
		goto R999;

	case 4: // STATE 8
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC Q */

	case 5: // STATE 2
		;
		now.inCriticalQ = trpt->bup.oval;
		;
		goto R999;

	case 6: // STATE 4
		;
		now.inCriticalQ = trpt->bup.oval;
		;
		goto R999;

	case 7: // STATE 8
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC P */

	case 8: // STATE 2
		;
		now.inCriticalP = trpt->bup.oval;
		;
		goto R999;

	case 9: // STATE 4
		;
		now.inCriticalP = trpt->bup.oval;
		;
		goto R999;

	case 10: // STATE 8
		;
		p_restor(II);
		;
		;
		goto R999;
	}

