/*-
 * Copyright (c) 2008-2009 Ed Schouten <ed@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

static void
teken_subr_cons25_set_cursor_type(teken_t *t, unsigned int type) {

    teken_funcs_param(t, TP_SHOWCURSOR, type != 1);
}

static const teken_color_t cons25_colors[8] = {TC_BLACK, TC_BLUE,
                                               TC_GREEN, TC_CYAN, TC_RED, TC_MAGENTA, TC_BROWN, TC_WHITE};

static void
teken_subr_cons25_set_adapter_background(teken_t *t, unsigned int c) {

    t->t_defattr.ta_bgcolor = cons25_colors[c % 8];
    t->t_curattr.ta_bgcolor = cons25_colors[c % 8];
}

static void
teken_subr_cons25_set_adapter_foreground(teken_t *t, unsigned int c) {

    t->t_defattr.ta_fgcolor = cons25_colors[c % 8];
    t->t_curattr.ta_fgcolor = cons25_colors[c % 8];
    if (c >= 8) {
        t->t_defattr.ta_format |= TF_BOLD;
        t->t_curattr.ta_format |= TF_BOLD;
    } else {
        t->t_defattr.ta_format &= ~TF_BOLD;
        t->t_curattr.ta_format &= ~TF_BOLD;
    }
}

static void
teken_subr_cons25_switch_virtual_terminal(teken_t *t, unsigned int vt) {

    teken_funcs_param(t, TP_SWITCHVT, vt);
}

