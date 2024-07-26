namespace qpp {
template <typename T>
class NoiseBase {
protected:
    void compute_probs_(const cmat& state, const std::vector<idx>& target, std::optional<std::string> caller = std::nullopt) const {
        // Implementação
    }

    cmat compute_state_(const cmat& state, const std::vector<idx>& target, std::optional<std::string> caller = std::nullopt) const {
        // Implementação
        return state; // Exemplo de retorno
    }

public:
    cmat operator()(const cmat& state) const {
        // Implementação
        compute_probs_(state, target, std::string("qpp::NoiseBase::operator()"));
        return compute_state_(state, target, std::string("qpp::NoiseBase::operator()"));
    }
};
}
