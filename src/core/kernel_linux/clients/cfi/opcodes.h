
OP_MACRO(OP_INVALID)
OP_MACRO(OP_UNDECODED)
OP_MACRO(OP_CONTD)
OP_MACRO(OP_LABEL)

OP_MACRO(OP_add)
OP_MACRO(OP_or)
OP_MACRO(OP_adc)
OP_MACRO(OP_sbb)
OP_MACRO(OP_and)
OP_MACRO(OP_daa)
OP_MACRO(OP_sub)
OP_MACRO(OP_das)
OP_MACRO(OP_xor)
OP_MACRO(OP_aaa)
OP_MACRO(OP_cmp)
OP_MACRO(OP_aas)
OP_MACRO(OP_inc)
OP_MACRO(OP_dec)
OP_MACRO(OP_push)
OP_MACRO(OP_push_imm)
OP_MACRO(OP_pop)
OP_MACRO(OP_pusha)
OP_MACRO(OP_popa)
OP_MACRO(OP_bound)
OP_MACRO(OP_arpl)
OP_MACRO(OP_imul)

OP_MACRO(OP_jo_short)
OP_MACRO(OP_jno_short)
OP_MACRO(OP_jb_short)
OP_MACRO(OP_jnb_short)
OP_MACRO(OP_jz_short)
OP_MACRO(OP_jnz_short)
OP_MACRO(OP_jbe_short)
OP_MACRO(OP_jnbe_short)
OP_MACRO(OP_js_short)
OP_MACRO(OP_jns_short)
OP_MACRO(OP_jp_short)
OP_MACRO(OP_jnp_short)
OP_MACRO(OP_jl_short)
OP_MACRO(OP_jnl_short)
OP_MACRO(OP_jle_short)
OP_MACRO(OP_jnle_short)

OP_MACRO(OP_call)
OP_MACRO(OP_call_ind)
OP_MACRO(OP_call_far)
OP_MACRO(OP_call_far_ind)
OP_MACRO(OP_jmp)
OP_MACRO(OP_jmp_short)
OP_MACRO(OP_jmp_ind)
OP_MACRO(OP_jmp_far)
OP_MACRO(OP_jmp_far_ind)

OP_MACRO(OP_loopne)
OP_MACRO(OP_loope)
OP_MACRO(OP_loop)
OP_MACRO(OP_jecxz)

    /* point ld & st at eAX & al instrs)
     * hopefully time taken considering them doesn't offset that */
OP_MACRO(OP_mov_ld)
OP_MACRO(OP_mov_st)
    /* PR 250397: store of immed is mov_st not mov_imm)
     * which we address by sharing part of the mov_st template chain */
OP_MACRO(OP_mov_imm)
OP_MACRO(OP_mov_seg)
OP_MACRO(OP_mov_priv)

OP_MACRO(OP_test)
OP_MACRO(OP_lea)
OP_MACRO(OP_xchg)
OP_MACRO(OP_cwde)
OP_MACRO(OP_cdq)
OP_MACRO(OP_fwait)
OP_MACRO(OP_pushf)
OP_MACRO(OP_popf)
OP_MACRO(OP_sahf)
OP_MACRO(OP_lahf)

OP_MACRO(OP_ret)
OP_MACRO(OP_ret_far)

OP_MACRO(OP_les)
OP_MACRO(OP_lds)
OP_MACRO(OP_enter)
OP_MACRO(OP_leave)
OP_MACRO(OP_int3)
OP_MACRO(OP_int)
OP_MACRO(OP_into)
OP_MACRO(OP_iret)
OP_MACRO(OP_aam)
OP_MACRO(OP_aad)
OP_MACRO(OP_xlat)
OP_MACRO(OP_in)
OP_MACRO(OP_out)
OP_MACRO(OP_hlt)
OP_MACRO(OP_cmc)
OP_MACRO(OP_clc)
OP_MACRO(OP_stc)
OP_MACRO(OP_cli)
OP_MACRO(OP_sti)
OP_MACRO(OP_cld)
OP_MACRO(OP_std)


OP_MACRO(OP_lar)
OP_MACRO(OP_lsl)
OP_MACRO(OP_syscall)
OP_MACRO(OP_clts)
OP_MACRO(OP_sysret)
OP_MACRO(OP_invd)
OP_MACRO(OP_wbinvd)
OP_MACRO(OP_ud2a)


OP_MACRO(OP_nop_modrm)
OP_MACRO(OP_movntps)
OP_MACRO(OP_movntpd)
OP_MACRO(OP_wrmsr)
OP_MACRO(OP_rdtsc)
OP_MACRO(OP_rdmsr)
OP_MACRO(OP_rdpmc)
OP_MACRO(OP_sysenter)
OP_MACRO(OP_sysexit)

OP_MACRO(OP_cmovo)
OP_MACRO(OP_cmovno)
OP_MACRO(OP_cmovb)
OP_MACRO(OP_cmovnb)
OP_MACRO(OP_cmovz)
OP_MACRO(OP_cmovnz)
OP_MACRO(OP_cmovbe)
OP_MACRO(OP_cmovnbe)
OP_MACRO(OP_cmovs)
OP_MACRO(OP_cmovns)
OP_MACRO(OP_cmovp)
OP_MACRO(OP_cmovnp)
OP_MACRO(OP_cmovl)
OP_MACRO(OP_cmovnl)
OP_MACRO(OP_cmovle)
OP_MACRO(OP_cmovnle)

OP_MACRO(OP_punpcklbw)
OP_MACRO(OP_punpcklwd)
OP_MACRO(OP_punpckldq)
OP_MACRO(OP_packsswb)
OP_MACRO(OP_pcmpgtb)
OP_MACRO(OP_pcmpgtw)
OP_MACRO(OP_pcmpgtd)
OP_MACRO(OP_packuswb)
OP_MACRO(OP_punpckhbw)
OP_MACRO(OP_punpckhwd)
OP_MACRO(OP_punpckhdq)
OP_MACRO(OP_packssdw)
OP_MACRO(OP_punpcklqdq)
OP_MACRO(OP_punpckhqdq)
OP_MACRO(OP_movd)
OP_MACRO(OP_movq)
OP_MACRO(OP_movdqu)
OP_MACRO(OP_movdqa)
OP_MACRO(OP_pshufw)
OP_MACRO(OP_pshufd)
OP_MACRO(OP_pshufhw)
OP_MACRO(OP_pshuflw)
OP_MACRO(OP_pcmpeqb)
OP_MACRO(OP_pcmpeqw)
OP_MACRO(OP_pcmpeqd)
OP_MACRO(OP_emms)

OP_MACRO(OP_jo)
OP_MACRO(OP_jno)
OP_MACRO(OP_jb)
OP_MACRO(OP_jnb)
OP_MACRO(OP_jz)
OP_MACRO(OP_jnz)
OP_MACRO(OP_jbe)
OP_MACRO(OP_jnbe)
OP_MACRO(OP_js)
OP_MACRO(OP_jns)
OP_MACRO(OP_jp)
OP_MACRO(OP_jnp)
OP_MACRO(OP_jl)
OP_MACRO(OP_jnl)
OP_MACRO(OP_jle)
OP_MACRO(OP_jnle)

OP_MACRO(OP_seto)
OP_MACRO(OP_setno)
OP_MACRO(OP_setb)
OP_MACRO(OP_setnb)
OP_MACRO(OP_setz)
OP_MACRO(OP_setnz)
OP_MACRO(OP_setbe)
OP_MACRO(OP_setnbe)
OP_MACRO(OP_sets)
OP_MACRO(OP_setns)
OP_MACRO(OP_setp)
OP_MACRO(OP_setnp)
OP_MACRO(OP_setl)
OP_MACRO(OP_setnl)
OP_MACRO(OP_setle)
OP_MACRO(OP_setnle)

OP_MACRO(OP_cpuid)
OP_MACRO(OP_bt)
OP_MACRO(OP_shld)
OP_MACRO(OP_rsm)
OP_MACRO(OP_bts)
OP_MACRO(OP_shrd)
OP_MACRO(OP_cmpxchg)
OP_MACRO(OP_lss)
OP_MACRO(OP_btr)
OP_MACRO(OP_lfs)
OP_MACRO(OP_lgs)
OP_MACRO(OP_movzx)
OP_MACRO(OP_ud2b)
OP_MACRO(OP_btc)
OP_MACRO(OP_bsf)
OP_MACRO(OP_bsr)
OP_MACRO(OP_movsx)
OP_MACRO(OP_xadd)
OP_MACRO(OP_movnti)
OP_MACRO(OP_pinsrw)
OP_MACRO(OP_pextrw)
OP_MACRO(OP_bswap)
OP_MACRO(OP_psrlw)
OP_MACRO(OP_psrld)
OP_MACRO(OP_psrlq)
OP_MACRO(OP_paddq)
OP_MACRO(OP_pmullw)
OP_MACRO(OP_pmovmskb)
OP_MACRO(OP_psubusb)
OP_MACRO(OP_psubusw)
OP_MACRO(OP_pminub)
OP_MACRO(OP_pand)
OP_MACRO(OP_paddusb)
OP_MACRO(OP_paddusw)
OP_MACRO(OP_pmaxub)
OP_MACRO(OP_pandn)
OP_MACRO(OP_pavgb)
OP_MACRO(OP_psraw)
OP_MACRO(OP_psrad)
OP_MACRO(OP_pavgw)
OP_MACRO(OP_pmulhuw)
OP_MACRO(OP_pmulhw)
OP_MACRO(OP_movntq)
OP_MACRO(OP_movntdq)
OP_MACRO(OP_psubsb)
OP_MACRO(OP_psubsw)
OP_MACRO(OP_pminsw)
OP_MACRO(OP_por)
OP_MACRO(OP_paddsb)
OP_MACRO(OP_paddsw)
OP_MACRO(OP_pmaxsw)
OP_MACRO(OP_pxor)
OP_MACRO(OP_psllw)
OP_MACRO(OP_pslld)
OP_MACRO(OP_psllq)
OP_MACRO(OP_pmuludq)
OP_MACRO(OP_pmaddwd)
OP_MACRO(OP_psadbw)
OP_MACRO(OP_maskmovq)
OP_MACRO(OP_maskmovdqu)
OP_MACRO(OP_psubb)
OP_MACRO(OP_psubw)
OP_MACRO(OP_psubd)
OP_MACRO(OP_psubq)
OP_MACRO(OP_paddb)
OP_MACRO(OP_paddw)
OP_MACRO(OP_paddd)
OP_MACRO(OP_psrldq)
OP_MACRO(OP_pslldq)


OP_MACRO(OP_rol)
OP_MACRO(OP_ror)
OP_MACRO(OP_rcl)
OP_MACRO(OP_rcr)
OP_MACRO(OP_shl)
OP_MACRO(OP_shr)
OP_MACRO(OP_sar)
OP_MACRO(OP_not)
OP_MACRO(OP_neg)
OP_MACRO(OP_mul)
OP_MACRO(OP_div)
OP_MACRO(OP_idiv)
OP_MACRO(OP_sldt)
OP_MACRO(OP_str)
OP_MACRO(OP_lldt)
OP_MACRO(OP_ltr)
OP_MACRO(OP_verr)
OP_MACRO(OP_verw)
OP_MACRO(OP_sgdt)
OP_MACRO(OP_sidt)
OP_MACRO(OP_lgdt)
OP_MACRO(OP_lidt)
OP_MACRO(OP_smsw)
OP_MACRO(OP_lmsw)
OP_MACRO(OP_invlpg)
OP_MACRO(OP_cmpxchg8b)
OP_MACRO(OP_fxsave)
OP_MACRO(OP_fxrstor)
OP_MACRO(OP_ldmxcsr)
OP_MACRO(OP_stmxcsr)
OP_MACRO(OP_lfence)
OP_MACRO(OP_mfence)
OP_MACRO(OP_clflush)
OP_MACRO(OP_sfence)
OP_MACRO(OP_prefetchnta)
OP_MACRO(OP_prefetcht0)
OP_MACRO(OP_prefetcht1)
OP_MACRO(OP_prefetcht2)
OP_MACRO(OP_prefetch)
OP_MACRO(OP_prefetchw)


OP_MACRO(OP_movups)
OP_MACRO(OP_movss)
OP_MACRO(OP_movupd)
OP_MACRO(OP_movsd)
OP_MACRO(OP_movlps)
OP_MACRO(OP_movlpd)
OP_MACRO(OP_unpcklps)
OP_MACRO(OP_unpcklpd)
OP_MACRO(OP_unpckhps)
OP_MACRO(OP_unpckhpd)
OP_MACRO(OP_movhps)
OP_MACRO(OP_movhpd)
OP_MACRO(OP_movaps)
OP_MACRO(OP_movapd)
OP_MACRO(OP_cvtpi2ps)
OP_MACRO(OP_cvtsi2ss)
OP_MACRO(OP_cvtpi2pd)
OP_MACRO(OP_cvtsi2sd)
OP_MACRO(OP_cvttps2pi)
OP_MACRO(OP_cvttss2si)
OP_MACRO(OP_cvttpd2pi)
OP_MACRO(OP_cvttsd2si)
OP_MACRO(OP_cvtps2pi)
OP_MACRO(OP_cvtss2si)
OP_MACRO(OP_cvtpd2pi)
OP_MACRO(OP_cvtsd2si)
OP_MACRO(OP_ucomiss)
OP_MACRO(OP_ucomisd)
OP_MACRO(OP_comiss)
OP_MACRO(OP_comisd)
OP_MACRO(OP_movmskps)
OP_MACRO(OP_movmskpd)
OP_MACRO(OP_sqrtps)
OP_MACRO(OP_sqrtss)
OP_MACRO(OP_sqrtpd)
OP_MACRO(OP_sqrtsd)
OP_MACRO(OP_rsqrtps)
OP_MACRO(OP_rsqrtss)
OP_MACRO(OP_rcpps)
OP_MACRO(OP_rcpss)
OP_MACRO(OP_andps)
OP_MACRO(OP_andpd)
OP_MACRO(OP_andnps)
OP_MACRO(OP_andnpd)
OP_MACRO(OP_orps)
OP_MACRO(OP_orpd)
OP_MACRO(OP_xorps)
OP_MACRO(OP_xorpd)
OP_MACRO(OP_addps)
OP_MACRO(OP_addss)
OP_MACRO(OP_addpd)
OP_MACRO(OP_addsd)
OP_MACRO(OP_mulps)
OP_MACRO(OP_mulss)
OP_MACRO(OP_mulpd)
OP_MACRO(OP_mulsd)
OP_MACRO(OP_cvtps2pd)
OP_MACRO(OP_cvtss2sd)
OP_MACRO(OP_cvtpd2ps)
OP_MACRO(OP_cvtsd2ss)
OP_MACRO(OP_cvtdq2ps)
OP_MACRO(OP_cvttps2dq)
OP_MACRO(OP_cvtps2dq)
OP_MACRO(OP_subps)
OP_MACRO(OP_subss)
OP_MACRO(OP_subpd)
OP_MACRO(OP_subsd)
OP_MACRO(OP_minps)
OP_MACRO(OP_minss)
OP_MACRO(OP_minpd)
OP_MACRO(OP_minsd)
OP_MACRO(OP_divps)
OP_MACRO(OP_divss)
OP_MACRO(OP_divpd)
OP_MACRO(OP_divsd)
OP_MACRO(OP_maxps)
OP_MACRO(OP_maxss)
OP_MACRO(OP_maxpd)
OP_MACRO(OP_maxsd)
OP_MACRO(OP_cmpps)
OP_MACRO(OP_cmpss)
OP_MACRO(OP_cmppd)
OP_MACRO(OP_cmpsd)
OP_MACRO(OP_shufps)
OP_MACRO(OP_shufpd)
OP_MACRO(OP_cvtdq2pd)
OP_MACRO(OP_cvttpd2dq)
OP_MACRO(OP_cvtpd2dq)
OP_MACRO(OP_nop)
OP_MACRO(OP_pause)

OP_MACRO(OP_ins)
OP_MACRO(OP_rep_ins)
OP_MACRO(OP_outs)
OP_MACRO(OP_rep_outs)
OP_MACRO(OP_movs)
OP_MACRO(OP_rep_movs)
OP_MACRO(OP_stos)
OP_MACRO(OP_rep_stos)
OP_MACRO(OP_lods)
OP_MACRO(OP_rep_lods)
OP_MACRO(OP_cmps)
OP_MACRO(OP_rep_cmps)
OP_MACRO(OP_repne_cmps)
OP_MACRO(OP_scas)
OP_MACRO(OP_rep_scas)
OP_MACRO(OP_repne_scas)


OP_MACRO(OP_fadd)
OP_MACRO(OP_fmul)
OP_MACRO(OP_fcom)
OP_MACRO(OP_fcomp)
OP_MACRO(OP_fsub)
OP_MACRO(OP_fsubr)
OP_MACRO(OP_fdiv)
OP_MACRO(OP_fdivr)
OP_MACRO(OP_fld)
OP_MACRO(OP_fst)
OP_MACRO(OP_fstp)
OP_MACRO(OP_fldenv)
OP_MACRO(OP_fldcw)
OP_MACRO(OP_fnstenv)
OP_MACRO(OP_fnstcw)
OP_MACRO(OP_fiadd)
OP_MACRO(OP_fimul)
OP_MACRO(OP_ficom)
OP_MACRO(OP_ficomp)
OP_MACRO(OP_fisub)
OP_MACRO(OP_fisubr)
OP_MACRO(OP_fidiv)
OP_MACRO(OP_fidivr)
OP_MACRO(OP_fild)
OP_MACRO(OP_fist)
OP_MACRO(OP_fistp)
OP_MACRO(OP_frstor)
OP_MACRO(OP_fnsave)
OP_MACRO(OP_fnstsw)

OP_MACRO(OP_fbld)
OP_MACRO(OP_fbstp)


OP_MACRO(OP_fxch)
OP_MACRO(OP_fnop)
OP_MACRO(OP_fchs)
OP_MACRO(OP_fabs)
OP_MACRO(OP_ftst)
OP_MACRO(OP_fxam)
OP_MACRO(OP_fld1)
OP_MACRO(OP_fldl2t)
OP_MACRO(OP_fldl2e)
OP_MACRO(OP_fldpi)
OP_MACRO(OP_fldlg2)
OP_MACRO(OP_fldln2)
OP_MACRO(OP_fldz)
OP_MACRO(OP_f2xm1)
OP_MACRO(OP_fyl2x)
OP_MACRO(OP_fptan)
OP_MACRO(OP_fpatan)
OP_MACRO(OP_fxtract)
OP_MACRO(OP_fprem1)
OP_MACRO(OP_fdecstp)
OP_MACRO(OP_fincstp)
OP_MACRO(OP_fprem)
OP_MACRO(OP_fyl2xp1)
OP_MACRO(OP_fsqrt)
OP_MACRO(OP_fsincos)
OP_MACRO(OP_frndint)
OP_MACRO(OP_fscale)
OP_MACRO(OP_fsin)
OP_MACRO(OP_fcos)
OP_MACRO(OP_fcmovb)
OP_MACRO(OP_fcmove)
OP_MACRO(OP_fcmovbe)
OP_MACRO(OP_fcmovu)
OP_MACRO(OP_fucompp)
OP_MACRO(OP_fcmovnb)
OP_MACRO(OP_fcmovne)
OP_MACRO(OP_fcmovnbe)
OP_MACRO(OP_fcmovnu)
OP_MACRO(OP_fnclex)
OP_MACRO(OP_fninit)
OP_MACRO(OP_fucomi)
OP_MACRO(OP_fcomi)
OP_MACRO(OP_ffree)

OP_MACRO(OP_fucom)
OP_MACRO(OP_fucomp)
OP_MACRO(OP_faddp)
OP_MACRO(OP_fmulp)
OP_MACRO(OP_fcompp)
OP_MACRO(OP_fsubrp)
OP_MACRO(OP_fsubp)
OP_MACRO(OP_fdivrp)
OP_MACRO(OP_fdivp)
OP_MACRO(OP_fucomip)
OP_MACRO(OP_fcomip)


OP_MACRO(OP_fisttp)
OP_MACRO(OP_haddpd)
OP_MACRO(OP_haddps)
OP_MACRO(OP_hsubpd)
OP_MACRO(OP_hsubps)
OP_MACRO(OP_addsubpd)
OP_MACRO(OP_addsubps)
OP_MACRO(OP_lddqu)
OP_MACRO(OP_monitor)
OP_MACRO(OP_mwait)
OP_MACRO(OP_movsldup)
OP_MACRO(OP_movshdup)
OP_MACRO(OP_movddup)

    /* 3D-Now! instructions */
OP_MACRO(OP_femms)
OP_MACRO(OP_unknown_3dnow)
OP_MACRO(OP_pavgusb)
OP_MACRO(OP_pfadd)
OP_MACRO(OP_pfacc)
OP_MACRO(OP_pfcmpge)
OP_MACRO(OP_pfcmpgt)

OP_MACRO(OP_pfcmpeq)
OP_MACRO(OP_pfmin)
OP_MACRO(OP_pfmax)
OP_MACRO(OP_pfmul)
OP_MACRO(OP_pfrcp)
OP_MACRO(OP_pfrcpit1)
OP_MACRO(OP_pfrcpit2)
OP_MACRO(OP_pfrsqrt)
OP_MACRO(OP_pfrsqit1)
OP_MACRO(OP_pmulhrw)
OP_MACRO(OP_pfsub)
OP_MACRO(OP_pfsubr)
OP_MACRO(OP_pi2fd)
OP_MACRO(OP_pf2id)
OP_MACRO(OP_pi2fw)
OP_MACRO(OP_pf2iw)
OP_MACRO(OP_pfnacc)
OP_MACRO(OP_pfpnacc)
OP_MACRO(OP_pswapd)

    /* SSSE3 */
OP_MACRO(OP_pshufb)
OP_MACRO(OP_phaddw)
OP_MACRO(OP_phaddd)
OP_MACRO(OP_phaddsw)
OP_MACRO(OP_pmaddubsw)
OP_MACRO(OP_phsubw)
OP_MACRO(OP_phsubd)
OP_MACRO(OP_phsubsw)
OP_MACRO(OP_psignb)
OP_MACRO(OP_psignw)
OP_MACRO(OP_psignd)
OP_MACRO(OP_pmulhrsw)
OP_MACRO(OP_pabsb)
OP_MACRO(OP_pabsw)
OP_MACRO(OP_pabsd)
OP_MACRO(OP_palignr)

OP_MACRO(OP_popcnt)
OP_MACRO(OP_movntss)
OP_MACRO(OP_movntsd)
OP_MACRO(OP_extrq)
OP_MACRO(OP_insertq)
OP_MACRO(OP_lzcnt)
OP_MACRO(OP_pblendvb)
OP_MACRO(OP_blendvps)
OP_MACRO(OP_blendvpd)
OP_MACRO(OP_ptest)
OP_MACRO(OP_pmovsxbw)
OP_MACRO(OP_pmovsxbd)
OP_MACRO(OP_pmovsxbq)
OP_MACRO(OP_pmovsxdw)
OP_MACRO(OP_pmovsxwq)
OP_MACRO(OP_pmovsxdq)
OP_MACRO(OP_pmuldq)
OP_MACRO(OP_pcmpeqq)
OP_MACRO(OP_movntdqa)
OP_MACRO(OP_packusdw)
OP_MACRO(OP_pmovzxbw)
OP_MACRO(OP_pmovzxbd)
OP_MACRO(OP_pmovzxbq)
OP_MACRO(OP_pmovzxdw)
OP_MACRO(OP_pmovzxwq)
OP_MACRO(OP_pmovzxdq)
OP_MACRO(OP_pcmpgtq)
OP_MACRO(OP_pminsb)
OP_MACRO(OP_pminsd)
OP_MACRO(OP_pminuw)
OP_MACRO(OP_pminud)
OP_MACRO(OP_pmaxsb)
OP_MACRO(OP_pmaxsd)
OP_MACRO(OP_pmaxuw)
OP_MACRO(OP_pmaxud)
OP_MACRO(OP_pmulld)
OP_MACRO(OP_phminposuw)
OP_MACRO(OP_crc32)
OP_MACRO(OP_pextrb)
OP_MACRO(OP_pextrd)
OP_MACRO(OP_extractps)
OP_MACRO(OP_roundps)
OP_MACRO(OP_roundpd)
OP_MACRO(OP_roundss)
OP_MACRO(OP_roundsd)
OP_MACRO(OP_blendps)
OP_MACRO(OP_blendpd)
OP_MACRO(OP_pblendw)
OP_MACRO(OP_pinsrb)
OP_MACRO(OP_insertps)
OP_MACRO(OP_pinsrd)
OP_MACRO(OP_dpps)
OP_MACRO(OP_dppd)
OP_MACRO(OP_mpsadbw)
OP_MACRO(OP_pcmpestrm)
OP_MACRO(OP_pcmpestri)
OP_MACRO(OP_pcmpistrm)
OP_MACRO(OP_pcmpistri)

    /* x64 */
OP_MACRO(OP_movsxd)
OP_MACRO(OP_swapgs)

    /* VMX */
OP_MACRO(OP_vmcall)
OP_MACRO(OP_vmlaunch)
OP_MACRO(OP_vmresume)
OP_MACRO(OP_vmxoff)
OP_MACRO(OP_vmptrst)
OP_MACRO(OP_vmptrld)
OP_MACRO(OP_vmxon)
OP_MACRO(OP_vmclear)
OP_MACRO(OP_vmread)
OP_MACRO(OP_vmwrite)

    /* undocumented */
OP_MACRO(OP_int1)
OP_MACRO(OP_salc)
OP_MACRO(OP_ffreep)

    /* AMD SVM */
OP_MACRO(OP_vmrun)
OP_MACRO(OP_vmmcall)
OP_MACRO(OP_vmload)
OP_MACRO(OP_vmsave)
OP_MACRO(OP_stgi)
OP_MACRO(OP_clgi)
OP_MACRO(OP_skinit)
OP_MACRO(OP_invlpga)
    /* AMD though not part of SVM */
OP_MACRO(OP_rdtscp)

    /* Intel VMX additions */
OP_MACRO(OP_invept)
OP_MACRO(OP_invvpid)

    /* added in Intel Westmere */
OP_MACRO(OP_pclmulqdq)
OP_MACRO(OP_aesimc)
OP_MACRO(OP_aesenc)
OP_MACRO(OP_aesenclast)
OP_MACRO(OP_aesdec)
OP_MACRO(OP_aesdeclast)
OP_MACRO(OP_aeskeygenassist)

    /* added in Intel Atom */
OP_MACRO(OP_movbe)

    /* added in Intel Sandy Bridge */
OP_MACRO(OP_xgetbv)
OP_MACRO(OP_xsetbv)
OP_MACRO(OP_xsave)
OP_MACRO(OP_xrstor)
OP_MACRO(OP_xsaveopt)

    /* Keep these at the end so that ifdefs don't change internal enum values */
OP_MACRO(OP_jmpe)
OP_MACRO(OP_jmpe_abs)