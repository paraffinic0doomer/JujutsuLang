#!/usr/bin/env python3
"""
JujutsuLang Phase 3 Execution Engine
Simple interpreter for executing parsed JujutsuLang programs.

This will be integrated with the Bison parser to execute
variable declarations, assignments, and control flow.
"""

import sys
import re
from typing import Dict, Any, List, Tuple

class ExecutionEngine:
    """Runtime execution engine for JujutsuLang"""
    
    def __init__(self):
        self.variables: Dict[str, Any] = {}
        self.functions: Dict[str, Dict[str, Any]] = {}
        self.output: List[str] = []
        self.return_value = None
        self.break_flag = False
        self.continue_flag = False
        
    def log(self, message: str):
        """Output execution trace"""
        self.output.append(message)
        print(message)
    
    def execute_declaration(self, var_name: str, var_type: str, initial_value: Any = None):
        """Execute variable declaration"""
        self.variables[var_name] = initial_value if initial_value is not None else 0
        self.log(f"[EXEC] Variable '{var_name}' ({var_type}) = {self.variables[var_name]}")
    
    def execute_assignment(self, var_name: str, value: Any):
        """Execute variable assignment"""
        if var_name not in self.variables:
            raise RuntimeError(f"Undefined variable: {var_name}")
        self.variables[var_name] = value
        self.log(f"[EXEC] Assignment: {var_name} = {value}")
    
    def execute_binary_op(self, op: str, left: Any, right: Any) -> Any:
        """Execute binary operations"""
        try:
            if op == '+':
                result = left + right
            elif op == '-':
                result = left - right
            elif op == '*':
                result = left * right
            elif op == '/':
                if right == 0:
                    raise RuntimeError("Division by zero")
                result = left // right  # Integer division
            elif op == '%':
                if right == 0:
                    raise RuntimeError("Modulo by zero")
                result = left % right
            elif op == '<':
                result = 1 if left < right else 0
            elif op == '>':
                result = 1 if left > right else 0
            elif op == '<=':
                result = 1 if left <= right else 0
            elif op == '>=':
                result = 1 if left >= right else 0
            elif op == '==':
                result = 1 if left == right else 0
            elif op == '!=':
                result = 1 if left != right else 0
            elif op == '&&':
                result = 1 if (left and right) else 0
            elif op == '||':
                result = 1 if (left or right) else 0
            else:
                raise RuntimeError(f"Unknown operator: {op}")
            
            self.log(f"[EXEC] {left} {op} {right} = {result}")
            return result
        except Exception as e:
            raise RuntimeError(f"Error in operation: {e}")
    
    def execute_unary_op(self, op: str, operand: Any) -> Any:
        """Execute unary operations"""
        if op == '-':
            return -operand
        elif op == '!':
            return 1 if not operand else 0
        else:
            raise RuntimeError(f"Unknown unary operator: {op}")
    
    def execute_if_statement(self, condition: Any, then_block, else_block=None):
        """Execute if-else statement"""
        if condition:
            self.log(f"[EXEC] If condition true: executing then block")
            # Execute then_block
        else:
            self.log(f"[EXEC] If condition false: executing else block")
            # Execute else_block
    
    def execute_for_loop(self, init, condition, increment, body):
        """Execute for loop"""
        self.log(f"[EXEC] For loop: entering")
        iteration = 0
        while condition:
            if self.break_flag:
                self.break_flag = False
                break
            # Execute body
            if self.continue_flag:
                self.continue_flag = False
            iteration += 1
            if iteration > 10000:  # Safety limit
                raise RuntimeError("Infinite loop detected")
        self.log(f"[EXEC] For loop: exited after {iteration} iterations")
    
    def execute_while_loop(self, condition, body):
        """Execute while loop"""
        self.log(f"[EXEC] While loop: entering")
        iteration = 0
        while condition:
            if self.break_flag:
                self.break_flag = False
                break
            # Execute body
            if self.continue_flag:
                self.continue_flag = False
            iteration += 1
            if iteration > 10000:  # Safety limit
                raise RuntimeError("Infinite loop detected")
        self.log(f"[EXEC] While loop: exited after {iteration} iterations")
    
    def execute_function_def(self, name: str, params: List[str], body):
        """Register function definition"""
        self.functions[name] = {
            'params': params,
            'body': body
        }
        self.log(f"[EXEC] Function defined: {name}({', '.join(params)})")
    
    def execute_function_call(self, name: str, args: List[Any]) -> Any:
        """Execute function call"""
        if name not in self.functions:
            raise RuntimeError(f"Undefined function: {name}")
        
        func_def = self.functions[name]
        self.log(f"[EXEC] Function call: {name}({', '.join(map(str, args))})")
        
        # Create new scope for function
        saved_vars = self.variables.copy()
        
        # Bind parameters
        for param, arg in zip(func_def['params'], args):
            self.variables[param] = arg
        
        # Execute function body
        result = self.return_value if self.return_value is not None else 0
        
        # Restore previous scope
        self.variables = saved_vars
        
        return result
    
    def get_variable(self, var_name: str) -> Any:
        """Get variable value"""
        if var_name not in self.variables:
            raise RuntimeError(f"Undefined variable: {var_name}")
        value = self.variables[var_name]
        self.log(f"[EXEC] Variable reference: {var_name} = {value}")
        return value

# Example usage
if __name__ == "__main__":
    engine = ExecutionEngine()
    
    # Test variable declaration
    engine.execute_declaration('x', 'int', 5)
    engine.execute_declaration('y', 'int', 10)
    
    # Test variable assignment
    engine.execute_assignment('x', 7)
    
    # Test binary operations
    result = engine.execute_binary_op('+', 5, 3)
    print(f"5 + 3 = {result}")
    
    result = engine.execute_binary_op('>', 5, 3)
    print(f"5 > 3 = {result}")
    
    # Test function definition
    engine.execute_function_def('add', ['a', 'b'], None)
