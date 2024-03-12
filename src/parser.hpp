#pragma once
#include "tokenization.hpp"

class Parser{
    public:

    private:
        [[nodiscard]] inline std::optional<Token> peek(int offset=0) const{
            if(m_index +offset >= m_tokens.size()){
                return {};
            }else{
                return m_tokens.at(m_index + offset);
            }
        }

        inline Token consume(){
            return m_tokens.at(m_index++);
        }

        const std::vector<Token> m_tokens;
        size_t m_index = 0;
};