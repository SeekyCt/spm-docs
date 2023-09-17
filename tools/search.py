"""
Searches for evt scripts in a ram dump
"""

from sys import argv


opcodes = {
	0x1: "end_script",
	0x2: "end_evt",
	0x3: "lbl",
	0x4: "goto",
	0x5: "do",
	0x6: "while",
	0x7: "do_break",
	0x8: "do_continue",
	0x9: "wait_frm",
	0xa: "wait_msec",
	0xb: "halt",
	0xc: "if_str_equal",
	0xd: "if_str_not_equal",
	0xe: "if_str_small",
	0xf: "if_str_large",
	0x10: "if_str_small_equal",
	0x11: "if_str_large_equal",
	0x12: "iff_equal",
	0x13: "iff_not_equal",
	0x14: "iff_small",
	0x15: "iff_large",
	0x16: "iff_small_equal",
	0x17: "iff_large_equal",
	0x18: "if_equal",
	0x19: "if_not_equal",
	0x1a: "if_small",
	0x1b: "if_large",
	0x1c: "if_small_equal",
	0x1d: "if_large_equal",
	0x1e: "if_flag",
	0x1f: "if_not_flag",
	0x20: "else",
	0x21: "end_if",
	0x22: "switch",
	0x23: "switchi",
	0x24: "case_equal",
	0x25: "case_not_equal",
	0x26: "case_small",
	0x27: "case_large",
	0x28: "case_small_equal",
	0x29: "case_large_equal",
	0x2a: "case_etc",
	0x2b: "case_or",
	0x2c: "case_and",
	0x2d: "case_flag",
	0x2e: "case_end",
	0x2f: "case_between",
	0x30: "switch_break",
	0x31: "end_switch",
	0x32: "set",
	0x33: "seti",
	0x34: "setf",
	0x35: "add",
	0x36: "sub",
	0x37: "mul",
	0x38: "div",
	0x39: "mod",
	0x3a: "addf",
	0x3b: "subf",
	0x3c: "mulf",
	0x3d: "divf",
	0x3e: "set_read",
	0x3f: "read",
	0x40: "read2",
	0x41: "read3",
	0x42: "read4",
	0x43: "read_n",
	0x44: "set_readf",
	0x45: "readf",
	0x46: "readf2",
	0x47: "readf3",
	0x48: "readf4",
	0x49: "readf_n",
	0x4a: "clamp_int",
	0x4b: "set_user_wrk",
	0x4c: "set_user_flg",
	0x4d: "alloc_user_wrk",
	0x4e: "and",
	0x4f: "andi",
	0x50: "or",
	0x51: "ori",
	0x52: "set_frame_from_msec",
	0x53: "set_msec_from_frame",
	0x54: "set_ram",
	0x55: "set_ramf",
	0x56: "get_ram",
	0x57: "get_ramf",
	0x58: "setr",
	0x59: "setrf",
	0x5a: "getr",
	0x5b: "getrf",
	0x5c: "user_func",
	0x5d: "run_evt",
	0x5e: "run_evt_id",
	0x5f: "run_child_evt",
	0x60: "delete_evt",
	0x61: "restart_evt",
	0x62: "set_pri",
	0x63: "set_spd",
	0x64: "set_type",
	0x65: "stop_all",
	0x66: "start_all",
	0x67: "stop_other",
	0x68: "start_other",
	0x69: "stop_id",
	0x6a: "start_id",
	0x6b: "chk_evt",
	0x6c: "inline_evt",
	0x6d: "inline_evt_id",
	0x6e: "end_inline",
	0x6f: "brother_evt",
	0x70: "brother_evt_id",
	0x71: "end_brother",
	0x72: "debug_put_msg",
	0x73: "debug_msg_clear",
	0x74: "debug_put_reg",
	0x75: "debug_name",
	0x76: "debug_rem",
	0x77: "debug_bp"
}

opcodesR = {}
for opc in opcodes:
	name = opcodes[opc]
	opcodesR[name] = opc

class BinaryReader:
    def __init__(self, path):
        self._f = open(path, 'rb')
    
    def __del__(self):
        self._f.close()

    def readat(self, addr, size):
        self._f.seek(addr - 0x80000000)
        return self._f.read(size)

    def readatS(self, addr):
        self._f.seek(addr - 0x80000000)
        strn = ""
        while True:
            c = self._f.read(1)[0]
            if c == 0:
                break
            strn += chr(c)
        return strn

    def readatI(self, addr, size):
        return int.from_bytes(self.readat(addr, size), 'big')

    def readatH(self, addr):
        return self.readatI(addr, 2)

    def readatW(self, addr):
        return self.readatI(addr, 4)
    
    def readatWA(self, addr, length):
        return [self.readatW(addr + (i * 4)) for i in range(0, length)]

expectedCmdns = {
    opcodesR["end_script"] : 0,
    opcodesR["end_evt"] : 0,
    opcodesR["lbl"] : 1,
    opcodesR["goto"] : 1,
    opcodesR["do"] : 1,
    opcodesR["while"] : 0,
    opcodesR["do_break"] : 0,
    opcodesR["do_continue"] : 0,
    opcodesR["wait_frm"] : 1,
    opcodesR["wait_msec"] : 1,
    opcodesR["halt"] : 1,
    opcodesR["if_str_equal"] : 2,
    opcodesR["if_str_not_equal"] : 2,
    opcodesR["if_str_small"] : 2,
    opcodesR["if_str_large"] : 2,
    opcodesR["if_str_small_equal"] : 2,
    opcodesR["if_str_large_equal"] : 2,
    opcodesR["iff_equal"] : 2,
    opcodesR["iff_not_equal"] : 2,
    opcodesR["iff_small"] : 2,
    opcodesR["iff_large"] : 2,
    opcodesR["iff_small_equal"] : 2,
    opcodesR["iff_large_equal"] : 2,
    opcodesR["if_equal"] : 2,
    opcodesR["if_not_equal"] : 2,
    opcodesR["if_small"] : 2,
    opcodesR["if_large"] : 2,
    opcodesR["if_small_equal"] : 2,
    opcodesR["if_large_equal"] : 2,
    opcodesR["if_flag"] : 2,
    opcodesR["if_not_flag"] : 2,
    opcodesR["else"] : 0,
    opcodesR["end_if"] : 0,
    opcodesR["switch"] : 1,
    # switchi
    opcodesR["case_equal"] : 1,
    opcodesR["case_not_equal"] : 1,
    opcodesR["case_small"] : 1,
    opcodesR["case_large"] : 1,
    opcodesR["case_small_equal"] : 1,
    opcodesR["case_large_equal"] : 1,
    opcodesR["case_etc"] : 0,
    opcodesR["case_or"] : 1,
    opcodesR["case_and"] : 1,
    opcodesR["case_flag"] : 1,
    opcodesR["case_end"] : 0,
    opcodesR["case_between"] : 2,
    opcodesR["switch_break"] : 0,
    opcodesR["end_switch"] : 0,
    opcodesR["set"] : 2,
    opcodesR["seti"] : 2,
    opcodesR["setf"] : 2,
    opcodesR["add"] : 2,
    opcodesR["sub"] : 2,
    opcodesR["mul"] : 2,
    opcodesR["div"] : 2,
    opcodesR["mod"] : 2,
    opcodesR["addf"] : 2,
    opcodesR["subf"] : 2,
    opcodesR["mulf"] : 2,
    opcodesR["divf"] : 2,
    opcodesR["set_read"] : 1,
    opcodesR["read"] : 1,
    opcodesR["read2"] : 2,
    opcodesR["read3"] : 3,
    opcodesR["read4"] : 4,
    opcodesR["read_n"] : 2,
    opcodesR["set_readf"] : 1,
    opcodesR["readf"] : 1,
    opcodesR["readf2"] : 2,
    opcodesR["readf3"] : 3,
    opcodesR["readf4"] : 4,
    opcodesR["readf_n"] : 2,
    opcodesR["clamp_int"] : 3,
    opcodesR["set_user_wrk"] : 1,
    opcodesR["set_user_flg"] : 1,
    opcodesR["alloc_user_wrk"] : 2,
    opcodesR["and"] : 2,
    opcodesR["andi"] : 2,
    opcodesR["or"] : 2,
    opcodesR["ori"] : 2,
    opcodesR["set_frame_from_msec"] : 2,
    opcodesR["set_msec_from_frame"] : 2,
    opcodesR["set_ram"] : 2,
    opcodesR["set_ramf"] : 2,
    opcodesR["get_ram"] : 2,
    opcodesR["get_ramf"] : 2,
    opcodesR["setr"] : 2,
    opcodesR["setrf"] : 2,
    opcodesR["getr"] : 2,
    opcodesR["getrf"] : 2,
    # user_func
    opcodesR["run_evt"] : 1,
    opcodesR["run_evt_id"] : 2,
    opcodesR["run_child_evt"] : 1,
    opcodesR["delete_evt"] : 1,
    opcodesR["restart_evt"] : 1,
    opcodesR["set_pri"] : 1,
    opcodesR["set_spd"] : 1,
    opcodesR["set_type"] : 1,
    opcodesR["stop_all"] : 1,
    opcodesR["start_all"] : 1,
    opcodesR["stop_other"] : 1,
    opcodesR["start_other"] : 1,
    opcodesR["stop_id"] : 1,
    opcodesR["start_id"] : 1,
    opcodesR["chk_evt"] : 2,
    opcodesR["inline_evt"] : 0,
    opcodesR["inline_evt_id"] : 1,
    opcodesR["end_inline"] : 0,
    opcodesR["brother_evt"] : 0,
    opcodesR["end_brother"] : 0,
    opcodesR["debug_put_msg"] : 1,
    # debug_msg_clear
    opcodesR["debug_put_reg"] : 1,
    opcodesR["debug_name"] : 1,
    # debug_rem
    # debug_bp
}

ram = BinaryReader(argv[1])

start = argv[2]
if start[:2] == '0x':
    start = start[2:]
start = int(start, 16) & ~3

end = argv[3]
if end[:2] == '0x':
    end = end[2:]
end = int(end, 16) + 3 & ~3

assert start < end

p = start
while p < end:
    scriptStart = p
    dbg = False

    if_depth = 0
    else_done = set()
    while_depth = 0
    switch_depth = 0
    inline_depth = 0
    brother_depth = 0

    while True:
        instr = ram.readatW(p)
        cmdn = ram.readatH(p)
        cmd = ram.readatH(p + 2)

        # Check opcode validity
        if ((cmdn | cmd) & 0xff00) or (cmd > 0x77) or (cmd == 0):
            # print(f"Rejecting {scriptStart:x} for out of range cmd/cmdn 0x{cmd:x} 0x{cmdn:x}")
            p = scriptStart + 4
            break

        # Check operand count
        if (cmd in expectedCmdns) and (expectedCmdns[cmd] != cmdn):
            # print(f"Rejecting {scriptStart:x} for bad cmdn 0x{cmdn:x} on {opcodes[cmd]}")
            p = scriptStart + 4
            break
        if (opcodes[cmd] in ["debug_msg_clear", "debug_rem", "debug_bp"]) and (cmdn > 5): # rough guess
            # print(f"Rejecting {scriptStart:x} for odd cmdn 0x{cmdn:x} on {opcodes[cmd]}")
            p = scriptStart + 4
            break

        # Check loop validity
        if opcodes[cmd] == "do":
            while_depth += 1
        if opcodes[cmd] == "while":
            while_depth -= 1
            if while_depth < 0:
                # print(f"Rejecting {scriptStart:x} for while without do")
                p = scriptStart + 4
                break
        if opcodes[cmd] in ["do_continue", "do_break"] and while_depth == 0:
            # print(f"Rejecting {scriptStart:x} for continue/break outside of loop")
            p = scriptStart + 4
            break

        # Check if validity
        if opcodes[cmd].startswith("if"):
            if_depth += 1
        if opcodes[cmd] == "else":
            if if_depth <= 0:
                # print(f"Rejecting {scriptStart:x} for else without if at {p:x}")
                p = scriptStart + 4
                break
            if if_depth in else_done:
                # print(f"Rejecting {scriptStart:x} for second else")
                p = scriptStart + 4
                break
            else_done.add(if_depth)
        if opcodes[cmd] == "end_if":
            if if_depth in else_done:
                else_done.remove(if_depth)
            if_depth -= 1

            # There are valid scripts where the devs made this mistake
            if_depth = max(if_depth, 0)
            # if if_depth < 0:
            #     # print(f"Rejecting {scriptStart:x} for end_if without if")
            #     p = scriptStart + 4
            #     break
        
        # Check switch validity
        if opcodes[cmd] == "switch":
            switch_depth += 1
        if opcodes[cmd] == "end_switch":
            switch_depth -= 1
            if switch_depth < 0:
                # print(f"Rejecting {scriptStart:x} for end_switch without switch")
                p = scriptStart + 4
                break
        if (
            (opcodes[cmd] == "switch_break" or opcodes[cmd].startswith("case_"))
            and switch_depth == 0
        ):
            # print(f"Rejecting {scriptStart:x} for case/break without switch")
            p = scriptStart + 4
            break

        # Check inline validity
        if opcodes[cmd].startswith("inline_evt"):
            inline_depth += 1
        if opcodes[cmd] == "end_inline":
            inline_depth -= 1
            if inline_depth < 0:
                # print(f"Rejecting {scriptStart:x} for end_inline without inline_evt")
                p = scriptStart + 4
                break

        # Check brother validity
        if opcodes[cmd].startswith("brother_evt"):
            brother_depth += 1
        if opcodes[cmd] == "end_brother":
            brother_depth -= 1
            if brother_depth < 0:
                # print(f"Rejecting {scriptStart:x} for end_brother without brother_evt")
                p = scriptStart + 4
                break

        p += cmdn * 4 + 4
        if cmd == 1:
            if p == scriptStart + 4:
                #print(f"Rejecting {scriptStart:x} for being too short")
                break
            if any(x != 0 for x in (
                if_depth,
                while_depth,
                switch_depth,
                inline_depth,
                brother_depth,
            )):
                print(f"Rejecting {scriptStart:x} for unclosed scope")
                break
            print(f"{scriptStart:08x}-{p-1:08x}")
            break
