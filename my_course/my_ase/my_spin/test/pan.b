	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC p */

	case 3: // STATE 2
		;
		((P0 *)this)->max = trpt->bup.oval;
		;
		goto R999;

	case 4: // STATE 4
		;
		((P0 *)this)->max = trpt->bup.oval;
		;
		goto R999;
;
		
	case 5: // STATE 7
		goto R999;

	case 6: // STATE 8
		;
		p_restor(II);
		;
		;
		goto R999;
	}

