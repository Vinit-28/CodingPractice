

// Question Link :: "https://leetcode.com/problems/simplify-path/"


// Solution //

class Solution:
    def simplifyPath(self, path: str) -> str:
        
        listOfCommands = [comm for comm in path.split('/')]
        pathList = []
        
        for comm in listOfCommands:
            if comm != "":
                
                if comm == "..":
                    if pathList != []:
                        pathList.pop()
                elif comm != ".":
                    pathList.append(comm)
        
        newPath = ""
        for directory in pathList:
            newPath += ("/" + directory)
        
        if newPath == "": 
            newPath = "/"
        return newPath