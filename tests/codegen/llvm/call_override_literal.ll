; ModuleID = 'bpftrace'
source_filename = "bpftrace"
target datalayout = "e-m:e-p:64:64-i64:64-n32:64-S128"
target triple = "bpf-pc-linux"

; Function Attrs: nounwind
declare i64 @llvm.bpf.pseudo(i64, i64) #0

define i64 @"kprobe:f"(i8*) section "s_kprobe:f_1" {
entry:
  %override = call i64 inttoptr (i64 58 to i64 (i8*, i64)*)(i8* %0, i64 -1)
  ret i64 0
}

attributes #0 = { nounwind }
